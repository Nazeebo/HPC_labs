#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <unistd.h>

void make_filename(int numberOfCow, char* filename){
    //sprintf(str,"log%d.txt",a);//bad practice in Production
    //snprintf(str,strSize,"log%.txt",a);//good practice, only in gcc
    char numOfCow[] = {numberOfCow + '0', '\0'};
    strcat(filename, "log");
    strcat(filename, numOfCow);
    strcat(filename, ".txt");
}

enum MessageTags {
        Eat,
        Milk,
        Dead
}

void cowWork(int rank){
    bool hungry = true;
    int numberOfCow = rank;
    char output[10] = "";
    make_filename(numberOfCow, output);
    std::ofstream out(output);
    srand(time(NULL));
    while(true){
        MPI_Ssend(0, 0, MPI_INT, 0, 0, MPI_COMM_WORLD);
        int hay;
        MPI_Status status;
        MPI_Recv(&hay, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,&status);
        if(hay > 0){
            out << "Cow got " << hay << " hay" << std::endl;
            int milk;
            milk = hay / 2;
            usleep((rand()%100000 +1));
            MPI_Ssend(&milk, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
            out << "Cow produced " << milk << " of milk" << std::endl;
        } else {
            out << "Cow died" << std::endl;
            break;
        }
    }
    return;
}

void farmerWork(int size, int &milk){ //TAG: 0 - cow is hungry, 1 - cow produced some amount of milk
    int cowCount = size - 1;
    int hay = 100;
    std::vector<bool> cows(cowCount, true);
    srand(time(NULL));
    while(true){
        MPI_Status status;
        int message;
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        int numOfCow = status.MPI_SOURCE;
        if(status.MPI_TAG == 0){
            int fake;
            MPI_Recv(&fake, 0, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);

            if(hay > 0){
                int message = 1 + rand() % 10;
                if(hay - message < 0)
                    message = hay;
                MPI_Ssend(&message, 1, MPI_INT, numOfCow, 0, MPI_COMM_WORLD); //(buf,count, datatype, dest,  msgtag, comm)
                hay -= message;
                std::cout << "Hay left: " << hay << std::endl;

            } else {
                int dead = -1;
                cowCount--;
                MPI_Ssend(&dead, 1, MPI_INT, numOfCow, 0, MPI_COMM_WORLD);
                cows[numOfCow - 1] = false;
                std::cout << "Cow number " << numOfCow << " was told to die" << std::endl;

                std::cout << "Cows' status:";
                for(int i = 0; i < cows.size(); ++i){
                    std::string status = cows[i] ? "alive" : "dead";
                    std::cout << " " << i+1 << " - " << status;
                    if (i == (cows.size() - 1) )
                        std::cout << ";";
                    else std::cout << ",";
                }
                std::cout << std::endl;
            }

        }
        else if(status.MPI_TAG == Milk){
            int milkGet;
            MPI_Status status;
            MPI_Recv(&milkGet, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
            milk+= milkGet;
            std::cout << "Farmer got " << milkGet << " milk from " << numOfCow << " cow" << std::endl;
        }
    if(cowCount <= 0)
        return;
    }
}

int main(int argc, char *argv[]){
        int rank, size, milk = 0;
        MPI_Init(&argc,&argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank); //get current process id
        MPI_Comm_size(MPI_COMM_WORLD, &size); //get current number of processees
        if( rank == 0)
            farmerWork(size, milk);
        else
            cowWork(rank);
        MPI_Barrier(MPI_COMM_WORLD);
        if( rank == 0)
            std::cout << "Milk produced: " << milk << std::endl;
        MPI_Finalize(); //end of parallel part of program
        return 0;
}

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class thread_guard{
    private:
        vector<thread> processes;
    public:
        thread_guard(){};

        void addThread(thread obj){
            processes.push_back(move(obj));
        }

        void allJoin(){  //wait
            for(int i = 0; i < processes.size();i++)
                if(processes[i].joinable())
                    processes[i].join();
        }

        ~thread_guard(){
            for(int i = 0; i < processes.size();i++)
                if(processes[i].joinable())
                    processes[i].join();
        }
        thread_guard(thread_guard &obj) = delete;
        thread_guard& operator=(thread_guard &obj) = delete;

};

void func(vector<int> a,vector<int> b,int &result, int number,int nThreads, int size){
    for(int i = number; i < size; i+=nThreads)
        result+= a[i] * b[i];
}

int main() {
    int nThreads = thread::hardware_concurrency();
    if (nThreads < 4)nThreads = 4;
    int size = 4,sum = 0;
    vector<int> a = {1,3,5,7},b = {2,6,8,2};
    vector<int> result= {0,0,0,0};
    thread_guard g;

    for(int i = 0; i < nThreads; i++){
        thread t(func,a,b,ref(result[i]),i,nThreads,size);
        g.addThread(move(t));
    }

    g.allJoin();

    for(int i = 0; i < nThreads; i++){
        sum += result[i];
        cout << result[i] << " ";
    }
    cout << endl;

    cout << sum << endl;

    return 0;
}
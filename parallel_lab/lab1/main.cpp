#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class thread_guard{
    private:
        vector<thread> processes;
    public:
        thread_guard(int nThreads, int m, vector<int> a,vector<int> b, vector<int> &result){

            void func(int &result, int number){
                int step = m/nThreads;
                for(int i = number; i <= m/nThreads; i+=step )
                    result+= a[i] * b[i];
            }

            for(int i = 0; i < nThreads; i++)
                processes.push_back(thread(func,ref(result[i]),i));
        }
        ~thread_guard(){
            for(int i = 0; i < processes.size();i++)
                if(processes[i].joinable())
                    processes[i].join();
        }
        thread_guard(thread_guard &obj) = delete;
        thread_guard& operator=(thread_guard &obj) = delete;

};



int main() {
    int nThreads = thread::hardware_concurrency();
    if (nThreads < 4)nThreads = 4;
    int size = 4,sum = 0;
    vector<int> a = {1,3,5,7},b = {2,6,8,2};
    vector<int> result= {0,0,0,0};
    thread_guard g(nThreads,size,a,b,result);

    delete[] &g;

    for(int i = 0; i < nThreads; i++)
        sum = sum + result[i];

    return 0;
}
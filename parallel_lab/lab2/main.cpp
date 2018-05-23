#include "defines.h"
#include "threadsave_stack.h"

class thread_guard {
private:
    vector<thread> processes;
public:
    thread_guard() = default;

    void addThread(thread obj) {
        processes.push_back(move(obj));
    }

    ~thread_guard() {
        for (int i = 0; i < processes.size(); i++)
            if (processes[i].joinable())
                processes[i].join();
    }

    thread_guard(thread_guard &obj) = delete;

    thread_guard &operator=(thread_guard &obj) = delete;

};


void func(const int number, threadsave_stack st) {
    string action;
    int data;
    if (number == 1) {
        ifstream in("file1.txt");
        ofstream log("log1.txt");
        while (!in.eof()) {
            in >> action;
            if (action == "push") {
                in >> data;
                //st.push(Data(data));
                st.push(data);
                log << "Pushed " << data << std::endl;
            }

            else if (action == "pop"){
                shared_ptr<Data> value = st.pop_top();
                log << "Poped " << value->data() << endl;
            }

        }
    } else if (number == 2) {
        ifstream in("file2.txt");
        ofstream log("log2.txt");
        while (!in.eof()) {
            in >> action;
            if (action == "push") {
                in >> data;
                //st.push(Data(data));
                st.push(data);
                log << "Pushed " << data << std::endl;
            } else if (action == "pop") {
                shared_ptr<Data> value = st.pop_top();
                log << "Poped " << value->data() << endl;
            }
        }
    }
    else if (number == 3) {
            ifstream in("file3.txt");
            ofstream log("log3.txt");
            while (!in.eof()) {
                in >> action;
                if (action == "push") {
                    in >> data;
                    //st.push(Data(data));
                    st.push(data);
                    log << "Pushed " << data << std::endl;
                } else if (action == "pop") {
                    shared_ptr<Data> value = st.pop_top();
                    log << "Poped " << value->data() << endl;
                }
            }
        }

}

int main() {
    thread_guard g;
    threadsave_stack st;
    for (int i = 0; i < 3; i++) {
        thread t(func, i, std::ref(st));
        g.addThread(move(t));
    }


    return 0;
}
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


void func(const int number, threadsave_stack<int>& st) {
    string action, input = "filex.txt", logs = "logx.txt";
    int data;
    input.replace(4,1,to_string(number));
    logs.replace(3,1,to_string(number));
    ifstream in(input);
    ofstream log(logs);
    while (!in.eof()) {
        in >> action;
        if (action == "push") {
            in >> data;
            st.push(data);
            log << "Pushed " << data << std::endl;
        } else if (action == "pop") {
            shared_ptr<int> value = st.pop_top();
            log << "Poped " << value.get() << endl;
        }

    }

}

int main() {
    thread_guard g;
    threadsave_stack<int> st;
    for (int i = 0; i < 3; i++) {
        thread t(func, i, std::ref(st));
        g.addThread(move(t));
    }

    return 0;
}
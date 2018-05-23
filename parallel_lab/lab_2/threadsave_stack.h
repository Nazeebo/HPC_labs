//
// Created by igor- on 23.05.2018.
//

#ifndef INC_2_THREADGUARDED_STACK_THREADSAVE_STACK_H
#define INC_2_THREADGUARDED_STACK_THREADSAVE_STACK_H

#include "defines.h"

template <class Data>
class threadsave_stack {
private:
    stack<Data> _data;
    std::mutex _m;
public:
    shared_ptr<Data> pop_top() {
        shared_ptr<Data> data;
        std::lock_guard<std::mutex> lock(_m);
        if(_data.empty()){
            return nullptr;
        }
        else {
            data = make_shared<Data>(_data.top());
            _data.pop();
            return data;
        }

    }

    void push(Data value) {
        std::lock_guard<std::mutex> lock(_m);
        _data.push(value);
    }
};


#endif //INC_2_THREADGUARDED_STACK_THREADSAVE_STACK_H

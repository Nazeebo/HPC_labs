//
// Created by 1 on 29.10.2018.
//

#ifndef INC_4_SHARED_MUTEX_THREAD_GUARD_HPP
#define INC_4_SHARED_MUTEX_THREAD_GUARD_HPP
#include "defines.h"

class Thread_guard {
private:
	vector<thread> processes;
public:
	Thread_guard() = default;

	void addThread(thread obj);

	~Thread_guard();

	Thread_guard(Thread_guard &obj) = delete;

	Thread_guard &operator=(Thread_guard &obj) = delete;

};


#endif //INC_4_SHARED_MUTEX_THREAD_GUARD_HPP

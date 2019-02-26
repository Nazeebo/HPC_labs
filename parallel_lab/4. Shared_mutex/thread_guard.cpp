//
// Created by 1 on 29.10.2018.
//

#include "thread_guard.hpp"

void Thread_guard::addThread(thread obj) {
	processes.push_back(move(obj));
}

Thread_guard::~Thread_guard() {
	for (int i = 0; i < processes.size(); i++)
		if (processes[i].joinable())
			processes[i].join();
}
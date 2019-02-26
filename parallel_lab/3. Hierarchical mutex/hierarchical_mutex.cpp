//
// Created by 1 on 12.11.2018.
//

#include "hierarchical_mutex.hpp"

map<thread::id,stack<int>> Hierarchical_mutex::threads_priorities;

void Hierarchical_mutex::lock() {
	stack<int>& thread_priorities = get_thread_priorities();
	int current_priority = 0;
	if(!thread_priorities.empty())
		current_priority = thread_priorities.top();
	if(check_priority(thread_priorities.empty(),current_priority)){
		m.lock();
		thread_priorities.push(priority_);
	}
	else {
		cout << "Attempt to lock mutex with lower priority" << endl;
		throw std::logic_error("");
	}
}

void Hierarchical_mutex::unlock() {
	stack<int>& priorities = get_thread_priorities();
	priorities.pop();
	m.unlock();
}

bool Hierarchical_mutex::check_priority(const bool thread_priority_status, const int thread_current_priority) {
	return (priority_ <= thread_current_priority || thread_priority_status);
}

stack<int> &Hierarchical_mutex::get_thread_priorities() {
	return threads_priorities[get_id()];
}

Hierarchical_mutex::Hierarchical_mutex(int priority){
	priority_ = priority;
}
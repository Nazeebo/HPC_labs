//
// Created by 1 on 12.11.2018.
//

#ifndef INC_3_HIERARCHICAL_MUTEX_HIERARCHICAL_MUTEX_HPP
#define INC_3_HIERARCHICAL_MUTEX_HIERARCHICAL_MUTEX_HPP
#include "defines.h"

class Hierarchical_mutex {
private:
	int priority_;
	static map<thread::id, stack<int>> threads_priorities;
	mutex m;
	stack<int>& get_thread_priorities();
	bool check_priority(bool thread_priority_status, int thread_current_priority);
public:
	explicit Hierarchical_mutex(int priority);
	void lock();
	void unlock();
};


#endif //INC_3_HIERARCHICAL_MUTEX_HIERARCHICAL_MUTEX_HPP

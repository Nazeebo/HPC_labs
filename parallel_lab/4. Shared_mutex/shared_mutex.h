//
// Created by igor- on 06.06.2018.
//

#ifndef INC_4_SHARED_MUTEX_SHARED_MUTEX_H
#define INC_4_SHARED_MUTEX_SHARED_MUTEX_H

#include "defines.h"

class Shared_mutex {
private:
    mutex m_;
    std::atomic<int> readersCounter;
public:
	Shared_mutex();

    void shared_lock();
    void shared_unlock();

    void lock();
    void unlock();

};

#endif //INC_4_SHARED_MUTEX_SHARED_MUTEX_H

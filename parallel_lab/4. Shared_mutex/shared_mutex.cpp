//
// Created by 1 on 29.10.2018.
//
#include "shared_mutex.h"

Shared_mutex::Shared_mutex() {
	readersCounter = 0;
}

void Shared_mutex::shared_lock(){
	m_.lock();
	++readersCounter;
	m_.unlock();
}

void Shared_mutex::shared_unlock() {
	--readersCounter;
}

void Shared_mutex::lock() {
	m_.lock();
	while(readersCounter.load() > 0);
}

void Shared_mutex::unlock() {
	m_.unlock();
}




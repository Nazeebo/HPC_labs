#include "thread_guard.hpp"
#include "hierarchical_mutex.hpp"

Hierarchical_mutex high_level_mutex(1000);
Hierarchical_mutex low_level_mutex(500);
Hierarchical_mutex other_mutex(10);
int a = 0;

void other_mutex_func() {
	other_mutex.lock();
	a += 10;
	other_mutex.unlock();
}

void low_level_func() {
	low_level_mutex.lock();
	a += 500;
	low_level_mutex.unlock();
}

void high_level_func() {
	high_level_mutex.lock();
	a += 1000;
	high_level_mutex.unlock();
}

void thread_a(){
	high_level_func();
}

void thread_b(){
	low_level_func();
}

void thread_c(){
	other_mutex_func();
}

int main() {
	ofstream out("log.txt");
	//cout << thread::hardware_concurrency() << endl;
	{
		Thread_guard g;

		g.addThread(thread(thread_c));
		g.addThread(thread(thread_b));
		g.addThread(thread(thread_a));
	}

	cout << a << endl;

	return 0;
}
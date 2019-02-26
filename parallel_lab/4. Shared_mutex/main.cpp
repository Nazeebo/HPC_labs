#include "defines.h"
#include "shared_mutex.h"
#include "thread_guard.hpp"

Shared_mutex m;

void func(const int number) { //multi access for readers
	string action, input = "filex.txt";
	input.replace(4, 1, to_string(number));
	ifstream in(input);
	while (!in.eof()) {
		in >> action;
		if (action == "read") {
			m.shared_lock();
			std::this_thread::sleep_for(milliseconds(10));
			m.shared_unlock();
		} else if (action == "write") {
			m.lock();
			std::this_thread::sleep_for(milliseconds(10));
			m.unlock();
		}
	}
}

void func1(const int number) { //single access for readers
	string action, input = "filex.txt";
	input.replace(4, 1, to_string(number));
	ifstream in(input);
	while (!in.eof()) {
		in >> action;
		if (action == "read") {
			m.lock();
			std::this_thread::sleep_for(milliseconds(10));
			m.unlock();
		} else if (action == "write") {
			m.lock();
			std::this_thread::sleep_for(milliseconds(10));
			m.unlock();
		}
	}
}

int main() {
	auto start = high_resolution_clock::now();

	{
		Thread_guard g;

		for (int i = 0; i < 4; i++) {
			thread t(func1, i);
			g.addThread(move(t));
		}

	}

	auto stop = high_resolution_clock::now();

	cout << duration_cast<milliseconds>(stop - start).count() << endl;

	return 0;
}
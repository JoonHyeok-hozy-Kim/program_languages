#include "15_01_thread.h"

#include <iostream>
#include <thread>
using std::thread;

namespace ThreadBasicTest {
	void func1() {
		for (int i = 0; i < 10; i++) {
			std::cout << "Thread 1 working.\n";
		}
	}

	void func2() {
		for (int i = 0; i < 10; i++) {
			std::cout << "Thread 2 working.\n";
		}
	}

	void func3() {
		for (int i = 0; i < 10; i++) {
			std::cout << "Thread 3 working.\n";
		}
	}

	void thread_basic_test() {
		thread t1(func1);
		thread t2(func2);
		thread t3(func3);

		t1.join();
		t2.join();
		t3.join();
	}

	void thread_detach_test() {
		thread t1(func1);
		thread t2(func2);
		thread t3(func3);

		t1.detach();
		t2.detach();
		t3.detach();

		std::cout << "Main Func ends." << std::endl;
	}
}

void thread_basic_test() {
	ThreadBasicTest::thread_basic_test();
}

void thread_detach_test() {
	ThreadBasicTest::thread_detach_test();
}


///////////////////////////////////////////////////////
/* Tech.) How to deliver parameters to threads.
	- ex.) Distributing summation example
*/

#include <cstdio>
#include <vector>
using std::vector;

namespace ThreadSumTest {
	void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
		int sum = 0;
		for (auto itr = start; itr < end; ++itr) {
			sum += *itr;
		}
		*result = sum;

		thread::id this_id = std::this_thread::get_id();
		printf("At thread %x, sum(%d, %d) = %d\n", this_id, *start, *(end - 1), sum);
	}

	void thread_distributed_sum_test() {
		vector<int> data(10000);
		for (int i = 0; i < 10000; i++) data[i] = i;

		vector<int> partial_sum(4);
		vector<thread> workers;

		for (int i = 0; i < 4; i++) {
			workers.push_back(
				thread(worker, 
					data.begin() + i * 2500, 
					data.begin() + (i + 1) * 2500,
					&partial_sum[i])
			);
		}
		
		for (int i = 0; i < 4; i++) {
			workers[i].join();
		}

		int total = 0;
		for (int i = 0; i < 4; i++) {
			total += partial_sum[i];
		}
		std::cout << "result : " << total << std::endl;
	}
}

void thread_distributed_sum_test() {
	ThreadSumTest::thread_distributed_sum_test();
}


///////////////////////////////////////////////////////
/* Tech.) How to share memory by threads
	- ex.) Threads increasing "counter" example
*/

namespace ThreadMemoryShareTest {
	void worker(int& counter) {
		for (int i = 0; i < 10000; i++) {
			counter += 1;
		}
	}

	void thread_increasing_counter() {
		int counter = 0;

		vector<thread> workers;
		for (int i = 0; i < 4; i++) {
			workers.push_back(thread(worker, std::ref(counter)));
		}

		for (int i = 0; i < 4; i++) {
			workers[i].join();
		}

		std::cout << "result : " << counter << std::endl;
	}
}

void thread_increasing_counter() {
	ThreadMemoryShareTest::thread_increasing_counter();
}
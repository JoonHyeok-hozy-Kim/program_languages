#include "15_02_mutex_condition_variable.h"


/* Race Condition
	- meaning : Problem that occurs when threads share a same memory
		- Consider the previous case that several programs are adding up a single variable, interfering each other.
	- Sol.) mutex
		- Comes from "Mutual Exclusion."
		- It gives an authority to use mutex objective only to one thread each time it locks!
		- Term) Critical Section : Codes between lock() and unlock(), which were allowed for only one thread.
*/

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace MutexTest {
	void worker(int& result, std::mutex& m) {
		for (int i = 0; i < 10000; i++) {
			m.lock();
			result += 1;
			m.unlock();
		}
	}

	void mutex_test() {
		int counter = 0;
		std::mutex m;

		std::vector<std::thread> workers;
		for (int i = 0; i < 4; i++) {
			workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
		}

		for (int i = 0; i < 4; i++) {
			workers[i].join();
		}

		std::cout << "Result : " << counter << std::endl;
	}
}

void mutex_simple_test() {
	MutexTest::mutex_test();
}

/* Concept) Deadlock
	- Check the example below.
	- Sol.) Add prevention logic!
*/

namespace DeadlockTest {
	void worker1(std::mutex& m1, std::mutex& m2) {
		for (int i = 0; i < 10000; i++) {
			std::lock_guard<std::mutex> lock1(m1);
			std::lock_guard<std::mutex> lock2(m2);
		}
	}

	void worker2(std::mutex& m1, std::mutex& m2) {
		for (int i = 0; i < 10000; i++) {
			std::lock_guard<std::mutex> lock2(m2);
			std::lock_guard<std::mutex> lock1(m1);
		}
	}

	void deadlock_simulation() {
		std::mutex m1, m2;
		std::thread t1(worker1, std::ref(m1), std::ref(m2));
		std::thread t2(worker2, std::ref(m1), std::ref(m2));

		t1.join();
		t2.join();

		std::cout << "End of the Program." << std::endl;
	}

	//////////////////////////////////////////////////////////
	/* Deadlock Prevention */
	void worker1_no_deadlock(std::mutex& m1, std::mutex& m2) {
		for (int i = 0; i < 10; i++) {
			m1.lock();
			m2.lock();
			std::cout << "Worker1's job" << std::endl;

			m2.unlock();
			m1.unlock();
		}
	}

	void worker2_no_deadlock(std::mutex& m1, std::mutex& m2) {
		for (int i = 0; i < 10; i++) {
			while (true) {
				m2.lock();
				
				if (!m1.try_lock()) {
					m2.unlock();
					continue;
				}

				std::cout << "Worker2's job" << std::endl;
				m1.unlock();
				m2.unlock();
				break;
			}
		}
	}

	void deadlock_prevention_implementation() {
		std::mutex m1, m2;
		std::thread t1(worker1_no_deadlock, std::ref(m1), std::ref(m2));
		std::thread t2(worker2_no_deadlock, std::ref(m1), std::ref(m2));

		t1.join();
		t2.join();

		std::cout << "End of the program." << std::endl;
	}
}


void mutex_deadlock_test() {
	DeadlockTest::deadlock_simulation();
}

void mutex_deadlock_prevention_implementation() {
	DeadlockTest::deadlock_prevention_implementation();
}


/* Concept) Producer and Consumer Pattern 
	- Structure
		- Producers create jobs and push them to a queue.
		- Consumers get jobs from the queue and operate them.
	- Check the example below.
*/

#include <chrono> // std::chrono::miliseconds
#include <queue>
#include <string>

namespace ProducerConsumerPattern {
	void producer(std::queue<std::string>* download_pages, std::mutex* m, int index) {
		for (int i = 0; i < 5; i++) {
			// Sleep for the time spent for downloading!
			std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));

			// Receiving data that will be processed in consumer threads.
			std::string content = "Webside : " + std::to_string(i) + " from thread(" +
				std::to_string(index) + ")\n";

			// Since download_pages is shared by threads, push operation took place in the critical section.
			m->lock();
			download_pages->push(content);
			m->unlock();
		}
	}

	void consumer(std::queue<std::string>* download_pages, std::mutex* m, int* num_processed) {		
		while (*num_processed < 25) {  // Five contents created by five producers = 25
			m->lock();

			if (download_pages->empty()) {
				m->unlock();
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
				continue;
			}

			std::string content = download_pages->front();
			download_pages->pop();

			(*num_processed)++;
			m->unlock();

			std::cout << content;
			std::this_thread::sleep_for(std::chrono::milliseconds(80));
		}
	}

	void test() {
		std::queue<std::string> downloaded_pages;
		std::mutex m;

		std::vector<std::thread> producers;
		for (int i = 0; i < 5; i++) {
			producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
		}

		int num_processed = 0;
		std::vector<std::thread> consumers;
		for (int i = 0; i < 3; i++) {
			consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_processed));
		}

		for (int i = 0; i < 5; i++) {
			producers[i].join();
		}

		for (int i = 0; i < 3; i++) {
			consumers[i].join();
		}
	}
}


void mutex_producer_consumer_pattern_test() {
	ProducerConsumerPattern::test();
}

/* Question) Is the Producer-Consumer-Pattern using mutex's lock() and unlock() efficient?
	- May be not.
		- Why?) Consumers constantly check the queue even if Producers haven created data.
	- What if there is a structure that alerts Consumers when Producers actually created data?
		-> condition_variable
*/

#include <condition_variable>

namespace ConditionVariableTest {
	void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, 
		int index, std::condition_variable* cv) {

		for (int i = 0; i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
			std::string content = "Webside : " + std::to_string(i) + " from thread(" +
				std::to_string(index) + ")\n";

			m->lock();
			downloaded_pages->push(content);
			m->unlock();

			// Here comes, condition_variable!!!
			cv->notify_one();
		}
	}

	void consumer(std::queue<std::string>* download_pages, std::mutex* m, 
		int* num_processed, std::condition_variable* cv) {

		while (*num_processed < 25) {
			std::unique_lock<std::mutex> lk(*m);	// unique_lock allows repeated lock() after unlock(). cv takes only unique_lock as input.

			// conditional variable will WAIT until the given condition is satisfied!!!
			cv->wait(lk, [&] { return !download_pages->empty() || *num_processed == 25; });

			if (*num_processed == 25) {
				lk.unlock();
				return;
			}

			std::string content = download_pages->front();
			download_pages->pop();

			(*num_processed)++;
			lk.unlock();

			std::cout << content;
			std::this_thread::sleep_for(std::chrono::milliseconds(80));
		}
	}

	void test() {
		std::queue<std::string> download_pages;
		std::mutex m;
		std::condition_variable cv;

		std::vector<std::thread> producers;
		for (int i = 0; i < 5; i++) {
			producers.push_back(std::thread(producer, &download_pages, &m, i + 1, &cv));
		}

		int numbers_processed = 0;
		std::vector<std::thread> consumers;
		for (int i = 0; i < 3; i++) {
			consumers.push_back(std::thread(consumer, &download_pages, &m, &numbers_processed, &cv));
		}

		for (int i = 0; i < 5; i++) {
			producers[i].join();
		}

		cv.notify_all();

		for (int i = 0; i < 3; i++) {
			consumers[i].join();
		}
	}
}


void mutex_condition_variable_test() {
	ConditionVariableTest::test();
}
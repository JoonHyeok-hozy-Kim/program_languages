#include "15_04_asynchronous.h"


/* Concept) Synchronous
	- Every operation is executed in the given order.
*/

/* Concept) Asynchronous
	- NOT synchronous
*/


#include <string>
#include <fstream>
#include <thread>
namespace AsynchronousTest {
	std::string do_something_with_string(std::string) {
		std::string result;
		return result;
	}

	void do_other_things() {}

	void synchronous_simple() {
		std::ifstream a("a.txt");
		std::string txt;
		std::string result;

		if (a.is_open()) {
			a >> txt;

			result = do_something_with_string(txt);
		}

		do_other_things();		// This job will wait until previous reading and do_something are done.
	}


	void read_file(std::string* result) {
		std::ifstream a("a.txt");
		std::string txt;
		
		if (a.is_open()) {
			a >> txt;

			*result = do_something_with_string(txt);
		}
	}

	void asynchronous_using_thread() {
		std::string result;
		std::thread t(read_file, &result);

		do_other_things;	// Simultaneously running with the thread t

		t.join();
	}
}


///////////////////////////////////////////////////////////////////////////////////////////
/* Tech) Special Tools for Asynchronous Programming in C++
	- std::promise
	- std::future
*/

#include <future>
#include <iostream>

using std::string;
namespace AsynchronousPromiseFuture {
	void worker(std::promise<string>* p) {
		p->set_value("some data");
	}

	void test() {
		std::promise<string> p;
		std::future<string> data = p.get_future();	// Promise that p will give result to data!
		std::thread t(worker, &p);

		data.wait();	// Wait until promise gives the result!

		std::cout << "Received data : " << data.get() << std::endl;		// Give result with get() method!

		t.join();
	}

}

void asynchornous_promise_future_test() {
	AsynchronousPromiseFuture::test();
}



// Implementing promise-future with mutex and condition_variable
#include <condition_variable>
#include <mutex>

namespace MimicPromiseFuture {
	std::condition_variable cv;
	std::mutex m;
	bool done = false;
	std::string info;

	void worker() {
		std::lock_guard<std::mutex> lk(m);
		info = "some data";
		done = true;

		cv.notify_all();
	}

	void test() {
		std::thread t(worker);
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk, [] { return done; });
		lk.unlock();

		std::cout << "Received Data : " << info << std::endl;

		t.join();
	}

}

void asynchornous_promise_future_mimic() {
	MimicPromiseFuture::test();
}



#include <exception>
// Tech.) std::future with exception
namespace AsynchronousExceptionTest {
	void worker(std::promise<string>* p) {
		try {
			throw std::runtime_error("Some Error");
		}
		catch (...) {
			p->set_exception(std::current_exception());		// std::current_exception() : Returns an exception pointer 
		}
	}

	void test() {
		std::promise<string> p;
		std::future<string> data = p.get_future();

		std::thread t(worker, &p);

		data.wait();

		try {
			data.get();
		}
		catch (const std::exception& e) {
			std::cout << "Exception : " << e.what() << std::endl;
		}
		
		t.join();
	}
}




// Tech.) wait_for() for future : Set time for waiting.
#include <chrono>

namespace FutureWaitForTest {
	void worker(std::promise<void>* p) {
		std::this_thread::sleep_for(std::chrono::seconds(10));
		p->set_value();
	}

	void test() {
		std::promise<void> p;
		std::future<void> data = p.get_future();
		std::thread t(worker, &p);

		while (true) {
			std::future_status status = data.wait_for(std::chrono::seconds(1));

			if (status == std::future_status::timeout) {
				std::cerr << ">";
			}
			else if (status == std::future_status::ready) {
				break;
			}
		}

		t.join();
	}
}

void asynchronous_future_wait_for_test() {
	FutureWaitForTest::test();
}


/* Concept) shared_future
	- A future that multiple threads can get()!
*/

namespace SharedFutureTest {
	void runner(std::shared_future<void> start, int num) {
		start.get();
		std::cout << "#" << num << ". Start!" << std::endl;
	}

	void test() {
		std::promise<void> p;
		std::shared_future<void> start = p.get_future();
		std::vector<std::thread> v;

		for (int i = 1; i <= 4; i++) {
			v.push_back(std::thread(runner, start, i));
		}

		std::cerr << "Ready...";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cerr << "Set, Go!" << std::endl;

		p.set_value();

		for (int i = 0; i < 4; i++) {
			v[i].join();
		}
	}
}

void asynchronous_shared_future_test() {
	SharedFutureTest::test();
}



/* Tech.) packaged_task
	- What is this?
		- A tool that applies promise-future pattern to an asynchronous function (precisely callable that includes functor and lambda function)
		- When a function returns value to the packaged_task, it set_value() to promise or set_exception().
*/

namespace PackagedTaskTest {
	int some_task(int x) { return 10 + x; }

	void test() {
		//        returns int   gets int
		//                 бщ   бщ
		std::packaged_task<int(int)> task(some_task);
		std::future<int> start = task.get_future();
		std::thread t(std::move(task), 5);
		std::cout << "Result : " << start.get() << std::endl;
		t.join();
	}
}

void asynchronous_packaged_task_test() {
	PackagedTaskTest::test();
}


/* Tech.) async
	- Not like packaged_task, async automatically creates std::thread!
	- More convenient!!!
*/

namespace AsyncTest{
	int sum(const std::vector<int>& v, int start, int end) {
		int total = 0;
		for (int i = start; i < end; i++) {
			total += v[i];
		}
		return total;
	}

	int parallel_sum(const std::vector<int>& v) {
		std::future<int> lower_half_future = std::async(std::launch::async, sum, cref(v), 0, v.size()/2);

		int upper_half = sum(v, v.size() / 2, v.size());

		return lower_half_future.get() + upper_half;
	}

	void parallel_summation_test() {
		std::vector<int> v;
		v.reserve(1000);

		for (int i = 0; i < 1000; i++) {
			v.push_back(i + 1);
		}

		std::cout << "Sum v : " << parallel_sum(v) << std::endl;
	}
}

void asynchronous_async_test() {
	AsyncTest::parallel_summation_test();
}
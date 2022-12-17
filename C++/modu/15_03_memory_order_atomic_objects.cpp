#include "15_03_memory_order_atomic_objects.h"

/* Concept) Modification Order
	- The order of modifications that certain objects went through.
	- Why need this?)
		- Its the common information that distintive threads ran on different CPUs can efficiently share.
		- Suppose that multiple threads, which run on different CPUs, access a single object for operations.
		- Recall that each CPU has cache memory for a faster opeartion.
			- Thus, when one thread modifies the object, another thread that access the object may witness different value of the object from the previous one.
			- i.e., depending on the moment of access, each thread can read different value of a same object.
			- Although the exact value of the object may differ, the order of modification will be compatible with each other.
				- Expensive synchronization may enable idential values at any time, but too costly.
		- Therfore, as long as the modification order maintains, identical value observed by each thread is not requried.
*/

/* Concept) Atomic Operation
	- An operation that is done by one thread and cannot be interfered by another thread.
	- The operation is atomic because it cannot be splitted.
	- Thus, atomic opeartions guarantee the Modification Order!
	- For objects that go through only Atomic Operations, does not need mutex.
		- Hence, the operations are way faster than other multi thread operations!
*/


#include <atomic>
#include <iostream>
#include <vector>
#include <thread>
namespace AtomicityTest {

	void worker(std::atomic<int>& counter, int worker_id) {
		for (int i = 0; i < 10; i++) {
			std::cout << "worker " << worker_id << ", counter : " << counter << std::endl;
			counter++;
		}
	}

	void basic_test() {
		std::atomic<int> counter(0);	// Declaration of an atomic object.

		std::vector<std::thread> workers;
		
		for (int i = 0; i < 4; i++) {
			workers.push_back(std::thread(worker, ref(counter), i));
		}

		for (int i = 0; i < 4; i++) {
			workers[i].join();
		}

		std::cout << "Result : " << counter << std::endl;
	}
}

void atomic_basic_test() {
	AtomicityTest::basic_test();
}


/* Tech.) memory order
	- An atomic object's memory access order determination
*/

// Type 1. memory_order_relaxed
//	- No restriction!
//	- Any process can intervene anytime! -> Very Fast!
#include <cstdio>
namespace MemoryOrderRelaxedTest {
	using std::memory_order_relaxed;

	void t1(std::atomic<int>* a, std::atomic<int>* b) {
		b->store(1, memory_order_relaxed);
		int x = a->load(memory_order_relaxed);

		printf("x : %d \n", x);
	}

	void t2(std::atomic<int>* a, std::atomic<int>* b) {
		a->store(1, memory_order_relaxed);
		int y = b->load(memory_order_relaxed);

		printf("y : %d \n", y);
	}

	void test() {
		std::vector<std::thread> threads;

		std::atomic<int> a(0);
		std::atomic<int> b(0);

		threads.push_back(std::thread(t1, &a, &b));
		threads.push_back(std::thread(t2, &a, &b));

		for (int i = 0; i < 2; i++) {
			threads[i].join();
		}
	}
}

void atomic_memory_order_relaxed_test() {
	for (int i = 1; i < 100; i++) {
		std::cout << "Test " << i << std::endl;
		MemoryOrderRelaxedTest::test();
		std::cout << std::endl;
	}
	
}


// Type 2. memory_order_release / memory_order_acquire
//    - memory_order_release : Prohibits processes called before it from going after it
//	  - memory_order_acquire : Prohibits processes called after it from going before it
namespace MemoryOrderReleaseAcquireTest {

	std::atomic<bool> is_ready = false;
	std::atomic<int> data[3];

	void producer() {
		data[0].store(1, std::memory_order_relaxed);
		data[1].store(2, std::memory_order_relaxed);
		data[2].store(3, std::memory_order_relaxed);
		is_ready.store(true, std::memory_order_release);	// Commands above cannot go below this line!
	}

	void consumer() {
		while (!is_ready.load(std::memory_order_acquire)) {}	// Commands below cannot go above this line!

		std::cout << "data[0] : " << data[0].load(std::memory_order_relaxed) << std::endl;
		std::cout << "data[1] : " << data[1].load(std::memory_order_relaxed) << std::endl;
		std::cout << "data[2] : " << data[2].load(std::memory_order_relaxed) << std::endl;
	}

	void release_acquire_test() {
		std::vector<std::thread> threads;
		threads.push_back(std::thread(producer));
		threads.push_back(std::thread(consumer));

		for (int i = 0; i < 2; i++) {
			threads[i].join();
		}
	}

	// For the comparison with memory_order_seq_cst
	void write_x(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		x->store(true, std::memory_order_release);
	}

	void write_y(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		y->store(true, std::memory_order_release);
	}

	void read_x_then_y(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		while (!x->load(std::memory_order_acquire)) {}
		if (y->load(std::memory_order_acquire)) {
			*z += 1;
		}
	}

	void read_y_then_x(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		while (!y->load(std::memory_order_acquire)) {}
		if (x->load(std::memory_order_acquire)) {
			*z += 1;
		}
	}

	void read_write_test() {
		std::atomic<bool> x = false;
		std::atomic<bool> y = false;
		std::atomic<int> z = 0;

		std::vector<std::thread> threads;

		threads.push_back(std::thread(write_x, &x, &y, &z));
		threads.push_back(std::thread(write_y, &x, &y, &z));
		threads.push_back(std::thread(read_x_then_y, &x, &y, &z));
		threads.push_back(std::thread(read_y_then_x, &x, &y, &z));

		for (int i = 0; i < 4; i++) {
			threads[i].join();
		}

		std::cout << "z : " << z << std::endl;
	}
}

void atomic_memory_order_release_acquire_test() {
	MemoryOrderReleaseAcquireTest::release_acquire_test();
}


// Type 4) memory_order_acq_rel
//	- (memory_order_acq_rel) = (memory_order_release) + (memory_order_acquire)
//	- For simultaneouly reading and writing processes such as fetch_add()


// Type 5) memory_order_seq_cst
//	- Guarantees Sequential Consistency(seq_cst)
//  - Every commands are executed with the sequence on the code!
namespace MemoryOrderSeqCstTest {
	void write_x(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		x->store(true, std::memory_order_seq_cst);
	}

	void write_y(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		y->store(true, std::memory_order_seq_cst);
	}

	void read_x_then_y(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		while (!x->load(std::memory_order_seq_cst)) {}
		if (y->load(std::memory_order_seq_cst)) {
			++(*z);
		}
	}

	void read_y_then_x(std::atomic<bool>* x, std::atomic<bool>* y, std::atomic<int>* z) {
		while (!y->load(std::memory_order_seq_cst)) {}
		if (x->load(std::memory_order_seq_cst)) {
			++(*z);
		}
	}

	void read_write_test() {
		std::atomic<bool> x = false;
		std::atomic<bool> y = false;
		std::atomic<int> z = 0;

		std::vector<std::thread> threads;

		threads.push_back(std::thread(write_x, &x, &y, &z));
		threads.push_back(std::thread(write_y, &x, &y, &z));
		threads.push_back(std::thread(read_x_then_y, &x, &y, &z));
		threads.push_back(std::thread(read_y_then_x, &x, &y, &z));

		for (int i = 0; i < 4; i++) {
			threads[i].join();
		}

		std::cout << "z : " << z << std::endl;
	}
}


void atomic_seq_std_comparison_test() {
	MemoryOrderReleaseAcquireTest::read_write_test();	// z in (0,1,2
	MemoryOrderSeqCstTest::read_write_test();			// z always 2
}
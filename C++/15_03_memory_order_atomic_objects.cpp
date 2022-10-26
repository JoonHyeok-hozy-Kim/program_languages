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
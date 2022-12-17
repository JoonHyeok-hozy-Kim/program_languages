#include "13_01_smart_pointer.h"
#include <iostream>


/* Why smart_pointer needed?
	- C++ does not support the garbage collecter.
	- Thus, if an object is not deleted by its destructor, it remains in the heap memory.
	- Remember that objects created in a function are automatically destructed when the function returns.
	- However, consider the case that a pointer of an object is created in a function but the function throws the exception and not ends properly.
	- Then, the object remains in the memory -> memory leak!
	- Check the example below!
*/

using namespace std;

namespace MemoryLeakCaseTest {
	class A {
		int* num;

	public:
		A() {
			num = new int[10];
			cout << "Creation." << endl;
		}

		~A() {
			delete[] num;
			cout << "Destruction." << endl;
		}

		void do_something() { cout << "A does something." << endl; }
	};

	void thrower(){
		cout << "Throw!" << endl;
		throw 1;
	}


	void memory_leak_test() {
		A* pa = new A();

		thrower();

		delete pa;		
	}
}

void smart_pointer_memory_leak_test() {

	try {
		MemoryLeakCaseTest::memory_leak_test();
	}
	catch (int i) {
		cout << "Exception" << i << endl;
	}
}


// Solution : Use smart pointer
/* Concept) Smart Pointer
	- It is created as a "pointer object" and deletes the data that it points when it is destructed.


	Concept) Unique Pointer (unique_ptr)
		- A pointer object that gives the UNIQUE ownership to the object that it points at. -> Enables RAII pattern : Resource Acquisition Is Initialization
		- Use "memory" header
*/

#include <memory>
namespace UniquePointerTest {
	
	// unique_ptr creation example
	void unique_ptr_test() {
		unique_ptr<MemoryLeakCaseTest::A> pa(new MemoryLeakCaseTest::A());	// How to use unique_ptr
		pa->do_something();		// Operates just like a pointer.
	}

	// Use move() to give away unique_ptr's possessing to another unique_ptr.
	void unique_ptr_move_test() {
		unique_ptr<MemoryLeakCaseTest::A> pa(new MemoryLeakCaseTest::A());
		cout << "pa : ";
		pa->do_something();

		unique_ptr<MemoryLeakCaseTest::A> pb = move(pa);	// MOVE!
		cout << "pb : ";
		pb->do_something();
	}

	// Perfect Forwardinng example
	void unique_ptr_as_an_input(MemoryLeakCaseTest::A* ptr) { ptr->do_something(); }

}

void smart_pointer_unique_ptr_test() {
	// Creation Example
	UniquePointerTest::unique_ptr_test();

	// Move example
	UniquePointerTest::unique_ptr_move_test();
}


/* Tech.) Perfect Forwarding for unique_ptr : Use the original pointer adress */
void smart_pointer_unique_ptr_forwarding_test() {
	unique_ptr<MemoryLeakCaseTest::A> pa(new MemoryLeakCaseTest::A());

	UniquePointerTest::unique_ptr_as_an_input(pa.get());	// Return the address using the get() function.
}


/* Tech.) std::make_unique : Easier way to create unique_ptr */
void smart_pointer_unique_ptr_make_unique() {
	auto ptr = make_unique<MemoryLeakCaseTest::A>();
	ptr->do_something();
}


#include <vector>
/* Tech.) Container having unique_pointers 
	- Method 1) Use move() so that it can overload the rvalue reference.
		- why?) Prevent the copying operation of unique_ptr.
	- Method 2) Use emplace_back
*/
void smart_pointer_unique_ptr_vector_test() {
	vector<unique_ptr<MemoryLeakCaseTest::A>> vec;
	unique_ptr<MemoryLeakCaseTest::A> pa(new MemoryLeakCaseTest::A());
	unique_ptr<MemoryLeakCaseTest::A> pb(new MemoryLeakCaseTest::A());

	vec.push_back(move(pa));
	vec.push_back(move(pb));
	vec.emplace_back(new MemoryLeakCaseTest::A());

	for (int i = 0; i < 3; i++) {
		vec[i]->do_something();
	}

}
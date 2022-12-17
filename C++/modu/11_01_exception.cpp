#include "11_01_exception.h"
#include <iostream>
#include <stdexcept>

namespace ExceptionTest {

	template <typename T>
	class Vector {
	private:
		T* data_;
		size_t size_;

	public:
		Vector(size_t size) : size_(size) {
			data_ = new T[size_];
			for (int i = 0; i < size_; i++) {
				data_[i] = 3;
			}
		}

		const T& at(size_t i) {
			if (i >= size_) {
				throw std::out_of_range("index out of range.");	// throw syntax
			}
			return data_[i];
		}

		~Vector() { delete data_; }
	};
}

void exception_simple_exception_test() {
	ExceptionTest::Vector<int> v(5);
	int data;
	for (int i = 0; i < 7; i++) {
		try {
			data = v.at(i);
		}
		catch (std::out_of_range& e) {
			std::cout << "[hozy Error]" << e.what() << std::endl;
		}

		std::cout << "data : " << data << std::endl;
	}
}

///////////////////////////////////////////////
/* Concept) stack unwinding
	- If an exception occurs, the process jumps to "catch" part and destructs every object on stack.
*/


namespace StackUnwindTest {

	class Resource {
	private:
		int id_;

	public:
		Resource(int id) : id_(id) {}
		~Resource() {
			std::cout << "[delete] Resource id_ : " << id_ << std::endl;
		}
	};

	int func3() {
		Resource r(3);
		throw std::runtime_error("Exception from func3.\n");	// Exception!
	}

	int func2() {
		Resource r(2);
		func3();
		std::cout << "func2 executed." << std::endl;
		return 0;
	}

	int func1() {
		Resource r(1);
		func2();
		std::cout << "func1 executed." << std::endl;
		return 0;
	}
}


void exception_stack_unwinding_test() {
	try {
		StackUnwindTest::func1();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
}



//////////////////////////////////////////
/* Tech.) Throwing various kinds of stuffs
*/

int exception_throw_various_func(int c) {
	switch (c) {
	case 1:
		throw 10;
	case 2:
		throw std::string("hi");
	case 3:
		throw 'a';
	case 4:
		throw "hello";
	default:
		return 0;
	}
	return 0;
}

void exception_throw_various_test() {
	int c;
	std::cin >> c;

	try {
		exception_throw_various_func(c);
	}
	catch (char x) {
		std::cout << "char : " << x << std::endl;
	}
	catch (int x) {
		std::cout << "int : " << x << std::endl;
	}
	catch (std::string x) {
		std::cout << "std::string : " << x << std::endl;
	}
	catch (const char* x) {
		std::cout << "string literal : " << x << std::endl;
	}
}


////////////////////////////////////////////////
/* Concept) Exception and Inheritance
	- Remember, in the "try~catch" syntax, child class's exception should come first.
	- If not, child class's exception will not work and only parent's will work.
*/

namespace ExceptionAndInheritance {
	class Parent : std::exception {
	public:
		const char* what() const noexcept override { return "Parent.\n"; }
	};

	class Child : Parent {
	public:
		const char* what() const noexcept override { return "Child.\n"; }
	};

	int throw_func(int c) {
		if (c == 1) {
			throw Parent();
		}
		else if (c==2) {
			throw Child();
		}
		return 0;
	}
}

void exception_inheritance_test() {

	// Wrong order : Parent catch first
	for (int i = 1; i <= 2; i++) {
		try {
			ExceptionAndInheritance::throw_func(i);
		}
		catch (ExceptionAndInheritance::Parent& p) {	// Parent first
			std::cout << "Parent catch" << std::endl;
			std::cout << p.what() << std::endl;
		}
		catch (ExceptionAndInheritance::Child& c) {
			std::cout << "Child catch" << std::endl;
			std::cout << c.what() << std::endl;
		}
	}

	// Right order : Child catch first
	for (int i = 1; i <= 2; i++) {
		try {
			ExceptionAndInheritance::throw_func(i);
		}
		catch (ExceptionAndInheritance::Child& c) {
			std::cout << "Child catch" << std::endl;
			std::cout << c.what() << std::endl;
		}
		catch (ExceptionAndInheritance::Parent& p) {
			std::cout << "Parent catch" << std::endl;
			std::cout << p.what() << std::endl;
		}
	}
}


////////////////////////////////////////////////
/* tech.) catch every exception
	- Use the following syntax
		try {} catch(...) {}
*/
int exception_catch_every_thing_func(int c) {
	if (c == 1) {
		throw 1;
	}
	else if (c == 2) {
		throw "hi";
	}
	else if (c == 3) {
		throw std::runtime_error("errrrror");
	}
	return 0;
}

void exception_catch_every_thing_test() {
	for (int i = 1; i <= 3; i++) {
		try {
			exception_catch_every_thing_func(i);
		}
		catch (int x) {
			std::cout << "int : " << x << std::endl;;
		}
		catch (...) {	// every exception except int!
			std::cout << "etc : " << std::endl;
		}
	}
}


//////////////////////////////////////////////////////
/* Concept) noexcept 
	- Complier treats a function with the "noexcept" keyword like it has no exception.
	- Thus, if exception happens in that function, the program ends without proper exception procedure.
*/
namespace NoexceptTest {
	int foo() noexcept { return 0; }	// foo is "noexcept".

	int bar() noexcept {  // bar is "noexcept" but throwing 1!
		throw 1; 
		return 0; 
	}	
}

void exception_noexcept_test() {
	NoexceptTest::foo();

	// Following does not work properly.
	/*try {
		NoexceptTest::bar();
	}
	catch (...) {
		std::cout << "Since bar() throws 1, should it be caught here?" << std::endl;
	}*/
}
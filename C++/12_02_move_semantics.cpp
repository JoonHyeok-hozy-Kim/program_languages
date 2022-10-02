#include "12_02_move_semantics.h"
#include <iostream>

/* Just like the movement(not the copy) of a rvlaue, let's try moving a lvalue. 
	Start with the swap operation.
*/

namespace CopySwapTest {

	// swap operation using COPY : 3 copy operations are made -> redundant
	template<typename T>
	void copy_swap(T& a, T& b) {
		T temp(a);		// copy	1
		a = b;			// copy	2
		b = temp;		// copy	3
	}
}

void move_semantics_copy_swap_test() {
	int a = 3;
	int b = 4;
	
	std::cout << a << ", " << b << std::endl;

	CopySwapTest::copy_swap(a, b);

	std::cout << a << ", " << b << std::endl;
}


// Instead, let's use move semantics.
/* Concept) move semantics
	- Implemented in utility.h
	- Alters lvalue into rvalue
*/

#include <utility>
namespace MoveSemanticsTest {

	class A {
	public:
		A() { std::cout << "Regular constructor." << std::endl; }
		A(const A& a) { std::cout << "Copy constructor." << std::endl; }
		A(A&& a) { std::cout << "Move constructor." << std::endl; }
	};

	template <typename T>
	void my_swap(T& a, T& b) {
		T temp(std::move(a));
		a = std::move(b);
		b = std::move(temp);
	}

	class B {
		A a_;

	public:
		B(A&& a) : a_(std::move(a)) {}	// Use move function when assigning class A
	};
}

void move_semantics_simple_test() {
	MoveSemanticsTest::A a;

	MoveSemanticsTest::A b(a);

	MoveSemanticsTest::A c(std::move(a));
}



#include "04_05_custom_string_class.h"

void move_semantics_MyString_test() {
	MyString s1 = "abc";
	MyString s2 = "def";

	s1.print();
	std::cout << " ";
	s2.println();
	MoveSemanticsTest::my_swap(s1, s2);

	s1.print();
	std::cout << " ";
	s2.println();
}


/* Tech.) How to construct a class that has a class as a member but using only using move constructors. */
void move_semantics_class_in_class_test() {

	MoveSemanticsTest::A a;
	std::cout << "Create B." << std::endl;
	MoveSemanticsTest::B b(std::move(a));

}



/* Concept) Perfect Forwarding and Universal Reference
	- Perfect Forwarding : How to forward [lvalue reference, const lvalue reference, and rvalue reference] without a loss or modification!
	- Universal Reference : Taking ONLY rvalue reference as a input!
		-> The compiler infers the type of the input parameter using "reference collapsing rule."

*/

// Consider the case of building a wrapper function
// Goal : Create a vector that contains A instances and push_back new A instances!
namespace WrapperFunctionTest {
	template<typename T>
	void wrapper(T u) {
		g(u);
	}

	class A {};

	void g(A& a) { std::cout << "Call lvalue reference" << std::endl; }
	void g(const A& a) { std::cout << "Call lvalue CONSTANT reference" << std::endl; }
	void g(A&& a) { std::cout << "Call rvalue reference" << std::endl; }

	// Sol2) Use universal reference!
	template<typename T>
	void wrapper_using_universal_ref(T&& u) {	// Takes ONLY rvalue reference!!
		g(std::forward<T>(u));	// std::forward works as std::move only if T is rvalue reference! Preventing error!
	}
}

void perfect_forwarding_wrapper_function_test() {
	WrapperFunctionTest::A a;
	const WrapperFunctionTest::A c_a;

	std::cout << "Original" << std::endl;
	WrapperFunctionTest::g(a);
	WrapperFunctionTest::g(c_a);
	WrapperFunctionTest::g(WrapperFunctionTest::A());

	// These call only the lvalue reference.
	//	-> Why?
	//		* The compiler ignores const keyword, unless wrapper function's type is not a reference.
	//		* General types need additional treatments!
	//			- Sol1) Create wrapper function for each case : void wrapper(T& u){...}; void wrapper(const T& u){...};
	//				-> Still lvalues... What about rvalue?
	//				-> Furthermore, what if there are multiple input parameters for the wrapper function? -> Annoying to create for every case.
	//			- Sol2) "Universal Reference"
	std::cout << "\nUsing Wrapper Function" << std::endl;
	WrapperFunctionTest::wrapper(a);
	WrapperFunctionTest::wrapper(c_a);
	WrapperFunctionTest::wrapper(WrapperFunctionTest::A());
}

void perfect_forwarding_wrapper_universal_ref_test() {
	WrapperFunctionTest::A a;
	const WrapperFunctionTest::A c_a;

	std::cout << "Original" << std::endl;
	WrapperFunctionTest::g(a);
	WrapperFunctionTest::g(c_a);
	WrapperFunctionTest::g(WrapperFunctionTest::A());

	std::cout << "\nUsing Wrapper Function with Universal Reference" << std::endl;
	WrapperFunctionTest::wrapper_using_universal_ref(a);
	WrapperFunctionTest::wrapper_using_universal_ref(c_a);
	WrapperFunctionTest::wrapper_using_universal_ref(WrapperFunctionTest::A());	// Works!
}
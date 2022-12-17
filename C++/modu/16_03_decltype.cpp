#include "16_03_decltype.h"

/* Concept.) decltype
	- Alters type into an inteded one.
	- Rules
		1) id-expressions (such as name of a variable, function, or enum, member variable or function of a class, etc)
			- Gets the exact type of the id-expression
		2) Non id-expressions
			Case1) The result of an expression is xvalue -> T&&
			Case2) The result of an expression is lvalue -> T&
			Case3) The result of an expression is prvalue -> T&
*/

#include <iostream>

namespace DecltypeIdExprssionCase {
	struct A {
		double d;
	};

	void test() {
		int a = 3;
		decltype(a) b = 2; // int
		std::cout << typeid(b).name() << std::endl;

		int& r_a = a;
		decltype(r_a) r_b = b; // int&
		std::cout << typeid(r_b).name() << std::endl;

		int&& x = 3;
		decltype(x) y = 2; // int&&
		std::cout << typeid(x).name() << std::endl;

		A* aa;
		decltype(aa->d) dd = 0.1;
		std::cout << typeid(dd).name() << std::endl;
	}
}


void decltype_id_expression_test() {
	DecltypeIdExprssionCase::test();
}


/* Concept) lvalue
	- Most objects that have name!
		- Variables
		- Function names
		- Data member of a type 
			- ex: std::cout, std::endl
		- Expression that returns the lvalue 
			- ex: "std::cout << 1" 
		- Assignment expressions
			- ex: "a = b", "a += b", "a *= b"
		- Pre-increment/decrement operator
			- ex : "++a", "--b"
		- Reference of a member that is NOT static
		- Array reference expressions
			- ex: a[i]
		- String literals
			- ex: "hi"
*/

/* Concept) prvalue
	- Every literals excluding string literals
		- ex : 42, true, nullptr
	- Expression that returns something not a reference
		- ex : "str.substr(1, 2)", "str1 + str2"
	- Post-increment/decrement operator
		- ex : "a++", "b--"
	- Arithmetic/Locial operator expressions
		- ex : "a + b", "a && b", "a < b"
	- Address operator expressions
		- ex : "&a"
	- Reference of a member that is NOT static
	- this
	- enum
	- lambda expressions
		- ex : "[]() { return 0; }"
*/

/* Concept) xvalue
	- Lvalue but capable of moving!
	- Ex.) Function that returns rvalue reference
		- ex.) std::move
*/


/////////////////////////////////////////////////////////////

/* Comparison) auto vs. decltype
	- Why simply not using auto, instead of decltype?
		-> auto is implicit alteration and sometimes omit siginficant information.
*/

namespace DecltypeAutoComparison {
	void test() {
		const int i = 4;
		auto j = i;				// int
		decltype(i) k = i;		// const int

		int arr[10];
		auto arr1 = arr;		// int* arr1 = arr;
		decltype(arr) arr2;		// int arr2[10]

	}

	template <typename T, typename U>
	void add(T t, U u, decltype(t + u)* result) {	// Holy sh*t!
		*result = t + u;
	}

	// or

	template <typename T, typename U>
	auto add(T t, U u) -> decltype(t + u) {
		return t + u;
	}
}

void decltype_auto_comparison() {
	DecltypeAutoComparison::test();
}



//////////////////////////////////////////////////////////
/* Tech.) std::declval function in <utility>
	- Why needed?
		- In case structures do not share the identical structure, especially with the shape of constructor, above decltype may not work.
			- ex.) Suppose struct A has a default constructor while struct B does not.
		- In that case, std::declval can be the solution!
			- why?) It returns the object type of the target struct
	- Caution) It cannot be used during the running time!
*/

#include <utility>
namespace DeclValTest {

	// 1. A struct with the default constructor
	struct A {
		int f() { return 0; }
	};

	// 2. A struct without a default constructor
	struct B {
		B(int x) {};	// Only custom constructor exists!
		int f() { return 0; }
	};

	// Error : (why?) B does not have a default constructor
	template <typename T>
	decltype(T().f()) wrong_call_f_and_return(T& t){
		return t.f();
	}

	// Correct way of using std::declval
	template <typename T>
	decltype(std::declval<T>().f()) correct_call_f_and_return(T& t) {
		return t.f();
	}
}

void decltype_declval_comparison_test() {
	DeclValTest::A a;
	DeclValTest::B b(1);

	std::cout << DeclValTest::wrong_call_f_and_return(a) << std::endl;;
	//DeclValTest::wrong_call_f_and_return(b);	// Wrong!

	std::cout << DeclValTest::correct_call_f_and_return(a) << std::endl;;
	std::cout << DeclValTest::correct_call_f_and_return(b) << std::endl;;

}
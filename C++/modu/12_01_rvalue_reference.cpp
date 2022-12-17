#include <iostream>
#include "12_01_rvalue_reference.h"


/* Copy Elision
	- If the copy of a construction is redundant, the compiler automatically skips it.
*/


namespace CopyElisionTest {
	class A {
		int data_;

	public:
		A(int data) : data_(data) { std::cout << "Regular Constructor" << std::endl; }

		A(const A& a) : data_(a.data_) { std::cout << "Copy Constructor" << std::endl; }
	};
}

void rvalue_copy_elision_test() {
	CopyElisionTest::A a1(1);
	CopyElisionTest::A a2(a1);

	CopyElisionTest::A a3(CopyElisionTest::A(4));	// Regular constructor called instead of the copy!

}


/////////////////////////////////////////////////////////////////////
/* Concept) lvalue : a value that comes at the left hand side of the equation
				- ex) i of "i = 3"
				- Prop.) lvalue can be at both LHS and RHS of any equation

   Concpet) rvalue : a value that comes at the right hand side of the equation
				- ex) 3 of "i = 3"
				- Prop.) rvalue can be only at RHS of any equation

	Concept) lvalue reference
		- Meaning : Only the lvalues can have the reference and we call it lvalue reference.
		- ex.) int i = 3; int& r_i = i;

	Concept) rvalue reference
		- Case when the type is "const T&" rvalue can get a reference.
		- ex.) Check the example below.
*/

#include "04_05_custom_string_class.h"
void rvalue_reference_test() {
	MyString a("abc");
	a.println();
	MyString b("cde");
	b.println();

	MyString c = a + b;
	c.println();
}


/////////////////////////////////////////////////////////
/* Concept) Moving Constructor
*/

MyString::MyString(MyString &&str) noexcept {	// For "noexcept" keyword, check below!
	std::cout << "Moving Constructor" << std::endl;
	string_length = str.string_length;
	string_content = str.string_content;
	capacity = str.capacity;

	// KEY POINT : Prevent complier from deleting memory when destructing temporary object!!!
	str.string_content = nullptr;
}

void rvalue_moving_constructor_test() {
	MyString a("abc");
	a.println();
	MyString b("cde");
	b.println();

	MyString c = a + b;
	c.println();
}


////////////////////////////////
/* Tech.) When adding an object using "moving constructor", you must add "noexcept" option
*/

#include <vector>
void rvalue_moving_constructor_noexcept_container_test() {
	MyString a("abc");
	std::vector<MyString> v;
	for (int i = 0; i < 5; i++) {
		std::cout << i << "-th push back" << std::endl;
		v.push_back(a);
	}

}
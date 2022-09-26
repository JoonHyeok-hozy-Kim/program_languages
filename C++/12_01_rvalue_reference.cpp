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
	MyString b("cde");

	MyString c = a + b;
}
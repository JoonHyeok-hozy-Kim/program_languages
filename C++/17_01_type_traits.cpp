#include "17_01_type_traits.h"


/* Concept) type_traits Library
	- Added since C++ 11
	- Supports Template Meta Functions for type related calculations
*/

/* Concept) Template Meta Funcion 
	- Meaning) Not a real function but works as one
	- Calculates for types not values.
*/

#include <iostream>
#include <type_traits>

namespace TemplateMetaFunctionSimpleTest {
	template <typename T>
	void tell_type() {
		if (std::is_void<T>::value) {	// "is_void" is a template meta function
			std::cout << typeid(T).name() << " is void!\n" << std::endl;
		}
		else {
			std::cout << typeid(T).name() << " is NOT void!\n" << std::endl;
		}
	}

	void test() {
		tell_type<int>();
		tell_type<void>();
	}
}

void template_meta_function_simple_test() {
	TemplateMetaFunctionSimpleTest::test();
}


/* Concept) "static_assert" keyword
	- A KEYWORD that receives a true/false expression
	- If the received expression is
		1) true: the program continues
		2) false: static_assert throws an error
*/

namespace TemplateMetaFunctionStaticAssertTest {
	class A {};

	template <typename T>
	void only_integer(const T& t) {
		static_assert(std::is_integral<T>::value);
		std::cout << typeid(T).name() << " is an integer." << std::endl;
	}

	void test() {
		int a;
		only_integer(a);	// Continues because "static_assert" is given true.

		A b;
		//only_integer(b);	// Throws error because "static_assert" is given false.
	}
}

void template_meta_function_static_assert_test() {
	TemplateMetaFunctionStaticAssertTest::test();
}


/* Concept) Pointer to Data Member
	- A pointer that points to a member of a class
		- Only applicable to classes and unions!
			- This trait will be used for is_class() function
	- Syntax : "_type_ T::*"
*/

namespace PointerToDataMemberTest {
	class A {
	public:
		int n;
		A(int n) : n(n) {};
	};

	void test() {
		int A::* p_n1 = &A::n;	// A pointer that points at n, a member of A

		A a(3);
		std::cout << "a.n = " << a.n << std::endl;
		std::cout << "a.*p_n1 = " << a.*p_n1 << std::endl;
	}
}

void pointer_to_data_member_test() {
	PointerToDataMemberTest::test();
}


/* Concept) SFINAE : Substitution Failure is NOT an Error
	- When a compiler compiles, if a certain expression does not makes sense, it will just be EXCLUDED for the candidates for the overloading,
		NOT returning error
	- Check the following example.
		- A goes to test(typename T::x a){...} and B goes to test(typename T::y b){...}
		- Each ignores the test that is not applicable, NOT returning error!
*/

namespace SFINAETest {
	template <typename T>
	void test(typename T::x a) {
		std::cout << "T::x" << std::endl;
	}

	template <typename T>
	void test(typename T::y b) {
		std::cout << "T::y" << std::endl;
	}

	struct A {
		using x = int;
	};

	struct B {
		using y = int;
	};

	void test() {
		std::cout << "test<A> ";
		test<A>(1);
		std::cout << "test<B> ";
		test<B>(2);
	}
}

void SFINAE_test() {
	SFINAETest::test();
}


/* Concept) is_class()
	- Determines whether the given type is a class
	- We will use following three concepts.
		1) Pointer to a data member
			- A pointer to the data member above to return true only if the given datatype is a class or a union!
		2) SFINAE
			- Substitution Failure is NOT an Error
			- If "Pointer to a data member" is applicable, do specific job, else don't!
		3) std::integral_constant<_type_, value>
			- A template that has certain value as its static object.
			- That certain value if the second input given between <(), (HERE!)>
			- ex.) std::integral_constant<bool, false>
				-> Meaning) std::intgeral_constant<bool, false>::value = false
*/


namespace TemplateMetaFunctionIsClassImplementation {

	namespace detail {
		// Option 1) Target T allows, "Pointer to Data Member," which is allowed only for classes and unions!!!
		//			 Thus, if T is not a class or a union, following syntax does not make sense and the compiler goes to Option 2). -> Refer to SFINAE
		template <class T>
		char test(int T::*);	// If T is a class, test<T>(x) is char!

		// Option 2) Generally, if ANY type T is given, test is constructed with the structure two,
		//			 which has a member c in the datatype char with its size of 2.
		struct two {
			char c[2];
		};
		template <class T>
		two test(...);			// If T is NOT a class, test<T> is a structure that has a char member of size 2.
	}


	// Finally, is_class() implementation
	template <class T>
	struct is_class
		: std::integral_constant<bool, size_of(detail::test<T>(0)) == 1	// true if T is a class. Why? test<T>(0) is char and size_of(char) = 1.
		&& !std::is_union<T>::value> {};	// Additional validation that "T is not a union" == "T is a class"

}


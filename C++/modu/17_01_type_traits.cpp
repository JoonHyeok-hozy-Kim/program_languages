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


/* Concept) enable_if
	- A Template Meta Function that excludes functions that do not qualify SFINAE from the overloading cadidates.
	- Syntax
		1) Put the target expression as input
		2) Return result type if the expression is true
	- Check the example below.
*/

namespace SFINAEEnableIfTest {

	// Example 1) Simple enable_if test for int
	template <typename T,
		typename = typename std::enable_if<std::is_integral<T>::value>::type>
	void int_check(const T& t) {
		std::cout << "t : " << t << std::endl;
	}

	struct A {
		int a;
	};

	void test() {
		std::cout << "Integer Data Types" << std::endl;
		int_check(1);		// int
		int_check(false);
		int_check('c');

		std::cout << "Non-Integer Data Types" << std::endl;
		//int_check(A{});		// NOT allowed!!!
	}


	// Example 2) Force specific datatype for enable_if
	// How to force Iterator type input for vector class implementation.
	// -> What is the difference btwn, vector_mk1 and vector_mk2?
	//	-> Recall that size_t is NOT int, an int without sign! On the other hand Iterator is an int type. Thus, the latter is chosen in mk1.
	//	  -> We can prevent this by forcing specific data type.
	template <typename T>
	class vector_mk1 {
	public:
		vector_mk1(size_t num, const T& element) {
			std::cout << "Create a vector that contains " << num << " number of " << element << std::endl;
		}

		template <typename Iterator>
		vector_mk1(Iterator start, Iterator end) {
			std::cout << "Create a vector with Iterators." << std::endl;
		}
	};


	template <typename T>
	class vector_mk2 {
	public:
		vector_mk2(size_t num, const T& element) {
			std::cout << "Create a vector that contains " << num << " number of " << element << std::endl;
		}

		template <typename Iterator,
			typename = typename std::enable_if<is_iterator<Iterator>::value>::type>
		vector_mk2(Iterator start, Iterator end) {
			std::cout << "Create a vector with Iterators." << std::endl;
		}
	};

	void vector_creation_test() {
		vector_mk1<int> v1(10, 3);
		vector_mk2<int> v2(10, 3);
	}


	// Example 3) Force certain class that contains certain member
	// We can actually accomplish this with decltype and std::declval.
	// However, if we want to force the return type of the member function, we can use enable if.

	// declval, std::decltype solution
	template <typename T, typename = decltype(std::declval<T>().func())>
	void contains_func(const T& t) {
		std::cout << "t.func() : " << t.func() << std::endl;
	}

	struct B {
		int func() const { return 1; }
	};

	void decltype_declval_test() {
		contains_func(B{});
		//contains_func(A{});		// Compile ERROR!
	}

	template <typename T,
		typename = typename std::enable_if<std::is_integral<decltype(std::declval<T>().func())>::value>::type>
	void contains_func_returns_int(const T& t) {
		std::cout << "t.func() : " << t.func() << std::endl;
	}

	struct C {
		B func() { return B{}; }
	};

	void forcing_return_test() {
		contains_func_returns_int(B{});
		//contains_func_returns_int(C{});		// Compile ERROR

		//contains_func(C{});	// NOT a compile error.	Cannot force the return type with this.
	}


	// Additional Example) How to call all the members of a container
	// print_all_elements() will be applied only for classes that have begin() and end().
	template <typename Cont, typename = decltype(std::declval<Cont>().begin()),
		typename = decltype(std::declval<Cont>().end())>
	void print_all_elements(const Cont& container) {
		std::cout << "[ ";
		for (auto it = container.begin(); it != container.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << "]\n";
	}
}

void SFINAE_enable_if_test() {
	SFINAEEnableIfTest::test();
}

void SFINAE_enable_if_forcing_type_test() {
	SFINAEEnableIfTest::vector_creation_test();
}

void SFINAE_enable_if_forcing_members_test() {
	SFINAEEnableIfTest::decltype_declval_test();
}


#include <vector>

void SFINAE_container_print_all_elements_test() {
	std::vector<int> a = { 1,2,3,4,5 };
	std::vector<char> c = { 'a','b','c','d' };
	SFINAEEnableIfTest::print_all_elements(a);
	SFINAEEnableIfTest::print_all_elements(c);
}


/* Tech.) void_t
	- Template input using variadic template
	- If the input template is valid, void_t becomes void, else excluded from overloading list (SFINAE)
	- Check the simplifying example of the container below.
*/
namespace SFINAEVoidTTest {
	// Simpler Version using void_t
	template <typename Cont>
	std::void_t<decltype(std::declval<Cont>().begin()), decltype(std::declval<Cont>().end())>
	print_all(const Cont& container) {
		std::cout << "[ ";
		for (auto it = container.begin(); it != container.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << "]\n";
	}

	struct B{};

	void print_all_test() {
		std::vector<int> v1 = { 1,2,3 };

		print_all(v1);
		//print_all<B, void>(B{});	// Again, excluded!

	}
}

void SFINAE_void_t_test() {
	SFINAEVoidTTest::print_all_test();
}
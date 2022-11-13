#include "16_02_constant_expression.h"


/* Def) Constant Expression
	- An expression that its result can be determined by compiler during the compiling time.

	Def.) Integral Constant Expression
	- A constant expression that the result value is an integer.

	Concept) constexpr : a keyword that denotes the constant expression

	Prop.) constexpr vs const
		- Both are constants.
		- However, constexpr must be initialized at compiling time.
		- On the other hand, const can be initialize at compiling time or running time depending on the compiler.
*/

#include <iostream>

namespace ConstExprTest1 {

	template <int N>
	struct A {
		int operator()() { return N; }
	};

	void test() {
		constexpr int size = 3;
		int arr[size];

		constexpr int N = 10;
		A<N> a;
		std::cout << a() << std::endl;

		constexpr int number = 3;
		enum B { x = number, y, z };
		std::cout << B::x << std::endl;
	}
}

void constant_expression_simple_test() {
	ConstExprTest1::test();
}



/* Tech.) Constant Expression Function
	- We can make a function that can be initialized during the compiling time.
	- Compare the simplicity of the code with the Template Meta Programming

	[Note] Followings cannot be used in a constant expression function
		1) goto clause
		2) exception : try ~ catch -> Allowed since C++20
		3) variable that is not a literal type
		4) variable that is not initialized.
		5) calling NOT constexpr function
*/

namespace ConstExprFuncTest {

	// Factorial Implementation

	// Method 1) Template Meta Programming
	template <int N>
	struct FactorialTMP {
		static const int value = N * FactorialTMP<N - 1>::value;
	};

	template <>
	struct FactorialTMP<0> {
		static const int value = 1;
	};

	// Method 2) Constant Expression Function
	constexpr int FactorialConsExpr(int n) {
		int result = 1;
		for (int i = 2; i <= n; i++) {
			result *= i;
		}
		return result;
	}


	template <int N>
	struct A {
		int operator()() { return N; }
	};


	void comparison() {
		A<FactorialTMP<10>::value> a;
		std::cout << "TMP Factorial : " << a() << std::endl;

		A<FactorialConsExpr(10)> b;
		std::cout << "Cons Expr Function Factorial : " << b() << std::endl;
	}
}

void constant_expression_function_test() {
	ConstExprFuncTest::comparison();
}


/* Concept) Literal Types?
	- Techincally, the types that are defined during the compiling time
	- ex)
		1) void type
		2) scalar types : char, int, bool, long, etc...
		3) reference type
		4) literal type array
		5) a type that satisfies the followings
			i)  Has default destructor
			ii) One of the followings
				- lambda function
				- aggregate type
				- contains constexpr constructor and does not contain copy or move constructor.
*/


/* Tech.) How to create constexpr constructor */
namespace ConstExprConstructor {
	class ConstExprVector {
	public:
		constexpr ConstExprVector(int x, int y) : x_(x), y_(y) {}

		constexpr int x() const { return x_; }
		constexpr int y() const { return y_; }

	private:
		int x_;
		int y_;
	};

	constexpr ConstExprVector add_const_expr_vector(const ConstExprVector& v1, const ConstExprVector& v2) {
		return { v1.x() + v2.x(), v1.y() + v2.y() };
	}

	template <int N>
	struct A {
		int operator()() { return N; }
	};

	
	void test() {
		constexpr ConstExprVector v1{ 1, 2 };
		constexpr ConstExprVector v2{ 3, 4 };

		A<v1.x()> a;
		std::cout << a() << std::endl;

		A<add_const_expr_vector(v1, v2).x()> b;
		std::cout << b() << std::endl;
	}
}

void constant_expression_constructor_test() {
	ConstExprConstructor::test();
}
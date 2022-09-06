#include <iostream>

namespace MetaProgramming {

	// Custom array class using template
	template <typename T, unsigned int N>
	class Array {
		T data[N];

	public:
		Array(T(&arr)[N]) {
			for (int i = 0; i < N; i++) {
				data[i] = arr[i];
			}
		}

		T* get_array() { return data; }

		unsigned int size() { return N; }

		void print() {
			std::cout << "[";
			for (int i = 0; i < N; i++) {
				std::cout << data[i];
				if (i < N - 1) std::cout << ", ";
			}
			std::cout << "]";
		}
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////

	// Custom Int struct
	template <int N>
	struct Int {
		static const int num = N;	// Why static const? Only type allowed for initialization at this point.
	};

	// Define custom addition operation.
	template <typename T, typename U>
	struct add {
		typedef Int<T::num + U::num> result;	// add structure's member, result, another Int struct!
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////

	// Custom Factorial
	template <int N>
	struct Factorial {
		static const int result = N * Factorial<N - 1>::result;
	};

	template <>
	struct Factorial<1> {
		static const int result = 1;
	};


	////////////////////////////////////////////////////////////////////////////////////////////////////

	// Greatest Common Divisor implementation using Template Meta Programming
	template <int N, int M>
	struct GCD {
		static const int result = GCD<M, N % M>::result;
	};

	template <int M>
	struct GCD<M, 0> {
		static const int result = M;
	};


	////////////////////////////////////////////////////////////////////////////////////////////////////

	// Ratio implementation using Template Meta Programming
	template <int Numerator, int Denominator>
	struct Ratio {
		typedef Ratio<Numerator, Denominator> type;		// Indicating the type of itself. Just like "this" keyword of a class.
		static const int numerator = Numerator;
		static const int denominator = Denominator;
	};

	template <class R1, class R2>
	struct _add_ratio {
		typedef Ratio<R1::numerator* R2::denominator + R1::denominator * R2::numerator, R1::denominator* R2::denominator> type;
	};

	template <class R1, class R2>
	struct add_ratio : _add_ratio<R1, R2>::type {};


	////////////////////////////////////////////////////////////////////////////////////////////////////

	// Fibonacci implementation using Template Meta Programming
	template <int N>
	struct Fibonacci {
		static const int num = Fibonacci<N - 1>::num + Fibonacci<N-2>::num;
	};

	template <>
	struct Fibonacci<2> {
		static const int num = 1;
	};

	template <>
	struct Fibonacci<1> {
		static const int num = 1;
	};


	////////////////////////////////////////////////////////////////////////////////////////////////////

	// Prime Number Validator using Template Meta Programming
	template <int N>
	bool PrimeNumberValidator{

	}
}

void custom_array_test();
void custom_int_test();
void custom_factorial_test();
void gcd_test();
void tmp_gcd_test();
void tmp_ratio_test();

// "using" keyword instead of "typedef"
void tmp_using_test();

void tmp_fibo_test();
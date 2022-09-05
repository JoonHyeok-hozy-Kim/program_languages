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

}

void custom_array_test();
void custom_int_test();
void custom_factorial_test();
void gcd_test();
void tmp_gcd_test();
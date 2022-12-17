//#pragma once
#include <iostream>
#include <string>
#include "09_03_template_meta_programming.h"
using namespace MetaProgramming;
namespace TMP {

	/* Prime Number Finder implementation */ 
	// 1. Use Int struct to paramenterize 1, 2, and 3.
	
	using one = Int<1>;
	using two = Int<2>;
	using three = Int<3>;

	template <typename N, typename D>
	struct check_div {
		static const bool result = (N::num % D::num == 0) || 
			check_div<N, typename add<D, one>::result>::result;		// Only type can come during template specialization. Must notify that an input is a type with the keyword "typename"
	};

	template <typename N>
	struct check_div<N, typename divide<N, two>::result> {
		static const bool result = (N::num % (N::num / 2) == 0);	// Quit recursion when D reaches N/2.
	};

	template <typename N>
	struct _is_prime {
		static const bool result = !check_div<N, two>::result;
	};

	template <int N>
	struct is_prime {
		static const bool result = _is_prime<Int<N>>::result;
	};



	/* More advanced Implementation of Ratio Class. */
	/* Greatest Common Divisor applied and "using" syntax instead of "typedef" syntax. */	
	template <int Numerator, int Denominator>
	struct NewRatio {
	private:
		static const int _gcd = GCD<Numerator, Denominator>::result;

	public:
		using type = NewRatio<Numerator / _gcd, Denominator / _gcd>;
		static const int numerator = Numerator / _gcd;
		static const int denominator = Denominator / _gcd;
	};

	template <class R1, class R2>
	struct _new_add_ratio {
		using type = NewRatio<R1::numerator* R2::denominator + R2::numerator * R1::denominator, R1::denominator* R2::denominator>;
	};

	template <class R1, class R2>
	struct new_add_ratio : _new_add_ratio<R1, R2>::type {};

	template <class R1, class R2>
	struct _new_subtract_ratio {
		using type = NewRatio<R1::numerator* R2::denominator - R2::numerator * R1::denominator, R1::denominator* R2::denominator>;
	};

	template <class R1, class R2>
	struct new_subtract_ratio : _new_subtract_ratio<R1, R2>::type {};

	template <class R1, class R2>
	struct _new_multiply_ratio {
		using type = NewRatio<R1::numerator* R2::numerator, R1::denominator* R2::denominator>;
	};

	template <class R1, class R2>
	struct new_multiply_ratio : _new_multiply_ratio<R1, R2>::type {};

	template <class R1, class R2>
	struct _new_divide_ratio {
		using type = NewRatio<R1::numerator* R2::denominator, R1::denominator* R2::numerator>;
	};

	template <class R1, class R2>
	struct new_divide_ratio : _new_divide_ratio<R1, R2>::type {};



	/* Unit Class implementation */
	/* Goal : Prevent situations where different units cannot be operated and return error */

	template <typename U, typename V, typename W>
	struct Dim {
		using Mass = U;		// in kilogram
		using Length = V;	// in meter
		using Time = W;		// in sec

		using type = Dim<Mass, Length, Time>;
	};

	template <typename U, typename V>
	struct add_dim_ {
		using type = Dim<typename new_add_ratio<typename U::Mass, typename V::Mass>::type,
			typename new_add_ratio<typename U::Length, typename V::Length>::type,
			typename new_add_ratio<typename U::Time, typename V::Time>::type>;
	};

	template <typename U, typename V>
	struct subtract_dim_ {
		using type = Dim<typename new_subtract_ratio<typename U::Mass, typename V::Mass>::type,
			typename new_subtract_ratio<typename U::Length, typename V::Length>::type,
			typename new_subtract_ratio<typename U::Time, typename V::Time>::type>;
	};

	template <typename T, typename D>
	struct quantity {
		T q;
		using dim_type = D;

		quantity operator+(quantity<T, D> other_quantity) {
			return quantity<T, D>(q + other_quantity.q);
		}

		quantity operator-(quantity<T, D> other_quantity) {
			return quantity<T, D>(q - other_quantity.q);
		}

		quantity(T q) : q(q) {}

		/* Multiplication and Division implementation */
		/* 1. Multiplication : addition for the unit and multiplication for the quantity q */
		template <typename D2>
		quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> other_quantity) {
			return quantity<T, typename add_dim_<D, D2>::type>(q * other_quantity.q);
		}

		/* 2. Division : subtraction for the unit and multiplicatio for the quantity q */
		template <typename D2>
		quantity<T, typename subtract_dim_<D, D2>::type> operator/(quantity<T, D2> other_quantity) {
			return quantity < T, typename subtract_dim_<D, D2>::type>(q / other_quantity.q);
		}

		/* 3. Scalar Multiplication and Division */
		quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar); }
		quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar); }
	};


	//////////////////////////////////////////////////////////////////////
	/* The auto keyword in C++ automatically detects and assigns a data type to the variable with which it is used.
	/* The compiler analyses the variable's data type by looking at its initialization. */

	// Example
	int int_sum_for_auto(int a, int b);

	class SomeClass {
		int data;

	public:
		SomeClass(int d) : data(d){}
		SomeClass(const SomeClass& s) : data(s.data) {}
	};

}

void tmp_is_prime_test();
void tmp_new_ratio_test();
void temp_unit_test();

void auto_keyword_test();
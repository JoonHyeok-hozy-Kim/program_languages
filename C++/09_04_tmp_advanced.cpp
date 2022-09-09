#include "09_04_tmp_advanced.h"
using namespace TMP;

void tmp_is_prime_test() {

	std::cout << 5 << " : " <<is_prime<5>::result << std::endl;
	std::cout << 6 << " : " <<is_prime<6>::result << std::endl;
	std::cout << 7 << " : " <<is_prime<7>::result << std::endl;
	std::cout << 8 << " : " <<is_prime<8>::result << std::endl;

}

void tmp_new_ratio_test() {

	using r1 = NewRatio<3, 21>;
	typedef NewRatio<4, 9> r2;

	using r3 = new_add_ratio<r1, r2>;
	std::cout << r3::numerator << " / " << r3::denominator << std::endl;

	using r4 = new_subtract_ratio<r1, r2>;
	std::cout << r4::numerator << " / " << r4::denominator << std::endl;

	using r5 = new_multiply_ratio<r1, r2>;
	std::cout << r5::numerator << " / " << r5::denominator << std::endl;

	using r6 = new_divide_ratio<r1, r2>;
	std::cout << r6::numerator << " / " << r6::denominator << std::endl;
	
}

void temp_unit_test() {
	using one = NewRatio<1, 1>;
	using zero = NewRatio<0, 1>;

	quantity<double, Dim<one, zero, zero>> kg(1);
	quantity<double, Dim<zero, one, zero>> meter(1);
	quantity<double, Dim<zero, zero, one>> second(1);

	std::cout << kg.q << std::endl;
	//std::cout << (kg + kg).q << std::endl;
	//std::cout << (kg + second).q << std::endl;	// Won't work!
}

int TMP::int_sum_for_auto(int a, int b) { return a + b; }

void auto_keyword_test() {
	auto c = int_sum_for_auto(1, 2);
	auto num = 1.0 + 2.0;

	SomeClass some(10);
	auto some2 = some;

	// Following fails.
	auto some3(10);
}
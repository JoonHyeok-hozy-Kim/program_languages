#include "09_03_template_meta_programming.h"


void custom_array_test() {
	int temp[5] = { 1,2,3,4,5 };
	MetaProgramming::Array<int, 5> test_array(temp);
	test_array.print();

	std::string temp_str[3] = { "a", "b", "c" };
	MetaProgramming::Array<std::string, 3> temp_str_array(temp_str);
	temp_str_array.print();

}


void custom_int_test() {

	typedef MetaProgramming::Int<1> n1;
	typedef MetaProgramming::Int<2> n2;

	typedef MetaProgramming::add<n1, n2>::result n3;

	std::cout << n1::num << " + " << n2::num << " = " << n3::num << std::endl;

}

void custom_factorial_test() {
	const int n = 6;
	std::cout << n << "! = " << MetaProgramming::Factorial<n>::result << std::endl;
}


// greatest common divisor using recursive method
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void gcd_test() {
	std::cout << gcd(126, 84) << std::endl;
}

void tmp_gcd_test() {
	std::cout << MetaProgramming::GCD<126, 84>::result << std::endl;
}

void tmp_ratio_test() {
	typedef MetaProgramming::Ratio<2, 3> r1;
	typedef MetaProgramming::Ratio<4, 7> r2;

	typedef MetaProgramming::add_ratio<r1, r2> r3;
	std::cout << "Addition : ";
	std::cout << r3::numerator << " / " << r3::denominator << std::endl;

	typedef MetaProgramming::deduct_ratio<r1, r2> r4;
	std::cout << "Deduction : ";
	std::cout << r4::numerator << " / " << r4::denominator << std::endl;

	typedef MetaProgramming::multiply_ratio<r1, r2> r5;
	std::cout << "Multiplication : ";
	std::cout << r5::numerator << " / " << r5::denominator << std::endl;

	typedef MetaProgramming::divide_ratio<r1, r2> r6;
	std::cout << "Division : ";
	std::cout << r6::numerator << " / " << r6::denominator << std::endl;
}

void tmp_using_test() {
	typedef MetaProgramming::Ratio<2, 3> r1;
	typedef MetaProgramming::Ratio<4, 7> r2;
	
	// "using"
	using r3 = MetaProgramming::add_ratio<r1, r2>;

	std::cout << r3::numerator << " / " << r3::denominator << std::endl;

}

void tmp_fibo_test() {
	std::cout << MetaProgramming::Fibonacci<1>::num << std::endl;
	std::cout << MetaProgramming::Fibonacci<2>::num << std::endl;
	std::cout << MetaProgramming::Fibonacci<3>::num << std::endl;
	std::cout << MetaProgramming::Fibonacci<4>::num << std::endl;
	std::cout << MetaProgramming::Fibonacci<5>::num << std::endl;
	std::cout << MetaProgramming::Fibonacci<6>::num << std::endl;
	std::cout << MetaProgramming::Fibonacci<7>::num << std::endl;
}
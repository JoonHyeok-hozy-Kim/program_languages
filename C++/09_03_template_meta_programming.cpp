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
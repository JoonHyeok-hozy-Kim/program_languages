#include "04_05_custom_string_class.h"
#include "05_01_operator_overloading.h"
#include <iostream>
#include <string.h>

bool MyString::operator==(MyString& str) {
	return !compare(str);	// Why "!compare(str)"? Recall that compare returns 0 if equal. operator== should return true if equal.
}

void equality_operator_test() {
	MyString str1("abc");
	MyString str2("abc");
	MyString str3("efg");

	std::cout << (str1 == str2) << std::endl;
	std::cout << (str1 == str3) << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////


void Complex::print() {
	std::cout << real;
	if (img >= 0) {
		std::cout << " + " << img;
	}
	else {
		std::cout << " - " << img*(-1);
	}
	std::cout << "i";
}

void Complex::println() {
	this->print();
	std::cout << std::endl;
}

Complex Complex::operator+(const Complex& c) const {
	Complex result(real + c.real, img + c.img);
	return result;
}

Complex Complex::operator-(const Complex& c) const {
	Complex result(real - c.real, img - c.img);
	return result;
}

Complex Complex::operator*(const Complex& c) const {
	double new_real = real * c.real - img * c.img;
	double new_img = real * c.img + c.real * img;
	Complex result(new_real, new_img);
	return result;
}

Complex Complex::operator/(const Complex& c) const {
	double nominator = c.real * c.real + c.img * c.img;
	double new_real = real * c.real + img * c.img;
	double new_img = real * c.img - c.real * img;
	Complex result(new_real / nominator, new_img / nominator);
	return result;
}

Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

Complex& Complex::operator+=(const Complex& c) {
	(*this) = (*this) + c;
	return (*this);
}

Complex& Complex::operator-=(const Complex& c) {
	(*this) = (*this) - c;
	return (*this);
}

Complex& Complex::operator*=(const Complex& c) {
	(*this) = (*this) * c;
	return (*this);
}

Complex& Complex::operator/=(const Complex& c) {
	(*this) = (*this) / c;
	return (*this);
}


void arithmetic_and_assignment_operator_overloading_test() {
	Complex a(2, 4);
	Complex b(1, 2);

	a.println();
	b.println();

	(a + b).println();
	(a - b).println();
	(a * b).println();
	(a / b).println();

	a += b;
	a.println();
	a -= b;
	a.println();
	a *= b;
	a.println();
	a /= b;
	a.println();

}

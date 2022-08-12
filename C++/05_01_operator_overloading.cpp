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
Complex::Complex(const char* str) {
	// str Format : [Pos/Neg] [real number] i [imaginary number]
	// ex) 1+2i, -12+3.7i, 3.8-0.3i
	bool real_neg = false;
	bool img_neg = false;
	int start;
	int end;
	int n = strlen(str);

	if (str[n - 1] != 'i') {
		img = 0;
		if (str[0] == '-') {
			real_neg = true;
			real = parse_number(str, 1, n - 1);
		}
		else real = parse_number(str, 0, n - 1);
	}
	else {
		end = n - 2;
		start = end;
		while (1) {
			if (str[start] != '+' && str[start] != '-') start--;
			else break;
		}
		if (start <= 0) {
			real = 0;			
			if (start == 0 && str[start] == '-') {
				img_neg = true;
				img = parse_number(str, 1, end);
			}
			else img = parse_number(str, 0, end);
		}
		else {
			img = parse_number(str, start + 1, end);
			if (start == 0 && str[start] == '-') img_neg = true;
			end = start-1;

			start = 0;
			if (str[start] == '-') {
				real_neg = true;
				start++;
			}
			real = parse_number(str, start, end);
		}

	}

	if (real_neg) real *= -1;
	if (img_neg) img *= -1;	
}

double parse_number(const char* str, int start, int end) {
	//std::cout << "parse_number ("<< start << " : " << end << ")" << std::endl;
	double result = 0;
	int period_digit = end+1;
	int digit_cnt = start;
	int temp_int;

	for (int i = start; i <= end; i++) {
		if (str[i] == '.') {
			period_digit = i;
			break;
		}
	}

	for (int i = start; i <= end; i++) {
		if (i == period_digit) continue;
		result += (double)(str[i] - '0') * pow(10, period_digit - digit_cnt - 1);
		//std::cout << result << std::endl;
		digit_cnt++;
	}

	return result;
}

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


void complex_string_constructor_test() {
	Complex a("12");
	//a.println();
	Complex b("-11");
	//b.println();
	Complex c("100+21i");
	//c.println();
	Complex d("-2000+312i");
	//d.println();
	Complex e("123-333i");
	//e.println();
	Complex f("-123-333i");
	//f.println();
	Complex g("12i");
	//g.println();
	Complex h("-177i");
	h.println();
}
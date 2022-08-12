

void equality_operator_test();


class Complex {
	double real, img;

public:
	//Complex() {}
	Complex(double real, double img) : real(real), img(img) {}
	//Complex(Complex& c) : real(c.real), img(c.img) {}
	Complex(const char* str);

	void print();
	void println();

	/* Arithmetic Operators */
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	/* Assignment Operators */
	Complex& operator=(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

};

double parse_number(const char* str, int start, int end);

void arithmetic_and_assignment_operator_overloading_test();
void complex_string_constructor_test();
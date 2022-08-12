

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


void arithmetic_and_assignment_operator_overloading_test();
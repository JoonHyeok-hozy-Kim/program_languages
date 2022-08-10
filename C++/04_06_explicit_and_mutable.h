#include <string.h>
#include <iostream>

class AllImplicitTestClass {

	int num;
	char* text;

public:
	AllImplicitTestClass(int num);
	AllImplicitTestClass(char c);
	AllImplicitTestClass(const char* str);

};

class ExplicitTestClass {

	int num;
	char* text;

public:
	explicit ExplicitTestClass(int num);	// explicit keyword prevents implicit construction!
	ExplicitTestClass(char c);
	ExplicitTestClass(const char* str);

};

void explict_test();


class MutableTestClass {
	mutable int data;

public:
	MutableTestClass(int data) : data(data) {}

	void print_data() const { std::cout << data << std::endl; }
	void data_update(int input) const { data = input; }
};

void mutable_test();
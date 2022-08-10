#include "04_06_explicit_and_mutable.h"


AllImplicitTestClass::AllImplicitTestClass(int num) {
	num = num;
	text = new char[num];
}

AllImplicitTestClass::AllImplicitTestClass(char c) {
	num = 1;
	text = new char[num];
	text[0] = c;
}

AllImplicitTestClass::AllImplicitTestClass(const char* str) {
	num = (int)strlen(str);
	text = new char[num];
	for (int i = 0; i < num; i++) {
		text[i] = str[i];
	}
}

ExplicitTestClass::ExplicitTestClass(int num) {
	num = num;
	text = new char[num];
}

ExplicitTestClass::ExplicitTestClass(char c) {
	num = 1;
	text = new char[num];
	text[0] = c;
}

ExplicitTestClass::ExplicitTestClass(const char* str) {
	num = (int)strlen(str);
	text = new char[num];
	for (int i = 0; i < num; i++) {
		text[i] = str[i];
	}
}

void do_something_with_all_implicit_test_class(AllImplicitTestClass aitc) {
	std::cout << "AllImplicitTestClass" << std::endl;
	//return;
}

void do_something_with_explicit_test_class(ExplicitTestClass etc) {
	std::cout << "ExplicitTestClass" << std::endl;
	//return;
}

void explict_test() {
	do_something_with_all_implicit_test_class(1); 
	do_something_with_all_implicit_test_class('c');
	do_something_with_all_implicit_test_class("abc");

	do_something_with_explicit_test_class(1);
	do_something_with_explicit_test_class('c');
	do_something_with_explicit_test_class("abc");
}

void mutable_test() {
	MutableTestClass a(10);

	a.print_data();
	a.data_update(11);
	a.print_data();
}
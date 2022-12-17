#include "06_01_inheritance.h"
#include <iostream>

/* C++ String Class */
#include <string.h>
void string_class_test() {
	std::string s = "abc";		// Considered as "const char*" data type

	std::cout << s << std::endl;
	std::cout << s.length() << std::endl;		// length

	std::string t = "def";	
	std::cout << s + t << std::endl;			// concat using + operator

	std::string u = "abc";
	std::cout << (s != t) << std::endl;			// comparison
	std::cout << (s == u) << std::endl;			// comparison

	return;
}



/* Inheritance */
class InheritanceTestBase {

// protected : accessible only to inherited classes
protected:
	std::string s_base;

public:
	InheritanceTestBase() : s_base("base") { std::cout << "base class instance constructed!" << std::endl; }

	void what() { std::cout << "s_base : " << s_base << std::endl; }
};


class InheritanceTestDerived : public InheritanceTestBase {
	std::string s_derived;

public:
	InheritanceTestDerived() : InheritanceTestBase(), s_derived("derived") { 
		std::cout << "derived class instance constructed!" << std::endl; 
		s_base = "not base";
	}

	void what() { std::cout << "s_derived : " << s_derived << std::endl; }		// method overriding

	void what_about_base() { std::cout << "s_base : " << s_base << std::endl; }		// access to the protected member!
};



void inheritance_test() {
	InheritanceTestBase base;
	base.what();

	InheritanceTestDerived derived;
	derived.what();
	derived.what_about_base();
}
#include "06_02_virtual_function_and_polymorphism.h"
#include <string.h>
#include <iostream>


class CastingTestBase {
	std::string s;

public:
	CastingTestBase() : s("base_string") { std::cout << "Base constructed" << std::endl; }
	
	void what() { std::cout << s << std::endl; }
};


class CastingTestDerived : public CastingTestBase {
	std::string s;

public:
	CastingTestDerived() : s("derived_string"), CastingTestBase() { std::cout << "Derived constructed" << std::endl; };

	void what() { std::cout << s << std::endl; }
};


// Up-Casting : Casting derived class into base class
void up_casting_test() {
	CastingTestBase base;
	CastingTestDerived derived;

	derived.what();

	CastingTestBase* p_base = &derived;		// up-casting
	p_base->what();

}

// Down-Casting : Casting base class into derived class (not suggested)
// Dynamic Casting : similar to static_casting
void down_casting_test() {
	CastingTestBase base;
	CastingTestDerived derived;

	base.what();

	CastingTestDerived* p_derived = static_cast<CastingTestDerived*>(&base);
	p_derived->what();

	//CastingTestBase* p_base;
	//CastingTestDerived* p_derived_dynamic = dynamic_cast<CastingTestDerived*>(p_base);	// dynamic casting
	//p_derived->what();

}


class DynamicBindingBase {
	std::string s;

public:
	DynamicBindingBase() : s("base") { std::cout << "Base constructed." << std::endl; }

	virtual void what() { std::cout << "Base's what()" << std::endl; }	// Indicate that what() method will be dynamically binded!
};


class DynamicBindingDerived : public DynamicBindingBase {
	std::string s;

public:
	DynamicBindingDerived() : s("derived"), DynamicBindingBase() { std::cout << "Derived constructed." << std::endl; }

	void what() override { std::cout << "Derived's what()" << std::endl; }
};


void dynamic_binding_test() {
	DynamicBindingBase base;
	DynamicBindingDerived derived;

	// Try upcasting!
	DynamicBindingBase* p_derived = &derived;
	p_derived->what();

	std::cout << "\n\n<Array Test>\n" << std::endl;
	// Test with array of objects
	DynamicBindingBase* array[4];
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) array[i] = new DynamicBindingBase();	// assign base class
		else array[i] = new DynamicBindingDerived();			// assign derived class
	}

	for (int i = 0; i < 4; i++) {
		array[i]->what();
	}
}
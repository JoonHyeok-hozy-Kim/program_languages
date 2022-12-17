#include "06_03_virtual_function_and_polymorphism_advanced.h"
#include <string.h>
#include <iostream>


// non-virtual destructor possessing parent
class NonVirtualDestructorTestBase {
	std::string s;

public:
	NonVirtualDestructorTestBase() : s("base_string") { std::cout << "Base constructed" << std::endl; }
	~NonVirtualDestructorTestBase() { std::cout << "Base destructed!" << std::endl; }	// Destructor, not virtual
};

// non-virtual destructor possessing child
class NonVirtualDestructorTestDerived : public NonVirtualDestructorTestBase {
	std::string s;

public:
	NonVirtualDestructorTestDerived() : s("derived_string"), NonVirtualDestructorTestBase() { std::cout << "Derived constructed" << std::endl; };
	~NonVirtualDestructorTestDerived() { std::cout << "Derived destructed!" << std::endl; }
};

// virtual destructor possessing parent
class VirtualDestructorTestBase {
	std::string s;

public:
	VirtualDestructorTestBase() : s("base_string") { std::cout << "Base constructed" << std::endl; }
	virtual ~VirtualDestructorTestBase() { std::cout << "Base destructed!" << std::endl; }	// Virtual Destructor

	virtual void show() { std::cout << "s : " << s << std::endl; }
};


// virtual destructor possessing child
class VirtualDestructorTestDerived : public VirtualDestructorTestBase {
	std::string s;

public:
	VirtualDestructorTestDerived() : s("derived_string"), VirtualDestructorTestBase() { std::cout << "Derived constructed" << std::endl; };
	~VirtualDestructorTestDerived() { std::cout << "Derived destructed!" << std::endl; }

	void show() override { std::cout << "s : " << s << std::endl; }
};


void virtual_destructor_test() {

	std::cout << "\n<Non Virtual Destructor case>" << std::endl;
	NonVirtualDestructorTestBase* arr[2];
	arr[0] = new NonVirtualDestructorTestBase();
	arr[1] = new NonVirtualDestructorTestDerived();

	// In this case, up-casted child class's instance is not deleted! Thus, destructor should be defined as virtual!
	for (int i = 0; i < 2; i++) {
		std::cout << i + 1 << "th destruction" << std::endl;
		delete arr[i];
	}


	std::cout << "\n<Virtual Destructor case>" << std::endl;
	VirtualDestructorTestBase* brr[2];
	brr[0] = new VirtualDestructorTestBase();
	brr[1] = new VirtualDestructorTestDerived();

	// In this case, up-casted child class's instance is also deleted!
	for (int i = 0; i < 2; i++) {
		std::cout << i + 1 << "th destruction" << std::endl;
		delete brr[i];
	}
}



// Virtual Function works well even when a reference of a class with virtual function is a input parameter of another function
void referece_input_virtual_function_test_func(VirtualDestructorTestBase& v) { 	v.show(); }		// reference of a class's instance as a function input parameter

void referece_input_virtual_function_test() {
	VirtualDestructorTestBase v_base;
	VirtualDestructorTestDerived v_derived;

	referece_input_virtual_function_test_func(v_base);
	referece_input_virtual_function_test_func(v_derived);
}



////////////////////////////////////////////////////////////////////////////////////
// Def.) pure virtual function : a function that should always be overrided by child class
// Def.) abstract class : a class consists of pure virtual functions.

class AnimalAbstractClass {
public:
	AnimalAbstractClass() {}
	virtual ~AnimalAbstractClass() {}	// virtual destructor
	
	virtual void make_sound() = 0;		// pure virtual function
};

class DogFromAnimalAbstractClass : public AnimalAbstractClass {
public:
	DogFromAnimalAbstractClass() : AnimalAbstractClass() {}
	~DogFromAnimalAbstractClass() {}

	void make_sound() override { std::cout << "Bark!" << std::endl; }
};

class CatFromAnimalAbstractClass : public AnimalAbstractClass {
public:
	CatFromAnimalAbstractClass() : AnimalAbstractClass(){}
	~CatFromAnimalAbstractClass() {}

	void make_sound() override { std::cout << "Meow~" << std::endl; }
};


void abstract_class_instanciation_test() {

	AnimalAbstractClass* a[2];
	a[0] = new DogFromAnimalAbstractClass();
	a[1] = new CatFromAnimalAbstractClass();

	for (int i = 0; i < 2; i++) {
		a[i]->make_sound();
	}

}

///////////////////////////////////////////////////////////////////////////////
// Multiple Inheritance
class MultipleInheritanceTestMom {
	int a;

public:
	MultipleInheritanceTestMom() : a(0) { std::cout << "mom created" << std::endl; }
	~MultipleInheritanceTestMom() {}

	void show_moms() { std::cout << "a : " << a << std::endl; }
};

class MultipleInheritanceTestDad {
	int b;

public:
	MultipleInheritanceTestDad() : b(1) { std::cout << "dad created" << std::endl; }
	~MultipleInheritanceTestDad() {}

	void show_dads() { std::cout << "b : " << b << std::endl; }
};

class MultipleInheritanceTestSon : public MultipleInheritanceTestDad, public MultipleInheritanceTestMom {
public:
	MultipleInheritanceTestSon() : MultipleInheritanceTestDad(), MultipleInheritanceTestMom() {}
	~MultipleInheritanceTestSon() {}
};

void multiple_inheritance_test() {

	MultipleInheritanceTestDad dad;
	MultipleInheritanceTestMom mom;
	MultipleInheritanceTestSon son;

	dad.show_dads();
	mom.show_moms();
	son.show_dads();
	son.show_moms();

}



////////////////////////////////////////////////////////////////
// How to Avoid Diamond Inheritance
// Def.) Diamond inheritance : inheriting from parents who are the children of an identical parent class
// Sol.) Parents may inherit their indentical parent as virtuals

class DiamondTestHuman {
	std::string name;

public:
	DiamondTestHuman() : name("HUMAN") { std::cout << name << "created" << std::endl; }

	void show_humans() { std::cout << "name : " << name << std::endl; }
};

class DiamondTestMom : public virtual DiamondTestHuman {		// inherit human as virtual
	int a;

public:
	DiamondTestMom() : a(0), DiamondTestHuman() { std::cout << "mom created" << std::endl; }
	~DiamondTestMom() {}

	void show_moms() { std::cout << "a : " << a << std::endl; }
};

class DiamondTestDad : public virtual DiamondTestHuman {		// inherit human as virtual
	int b;

public:
	DiamondTestDad() : b(1), DiamondTestHuman() { std::cout << "dad created" << std::endl; }
	~DiamondTestDad() {}

	void show_dads() { std::cout << "b : " << b << std::endl; }
};

class DiamondTestSon : public DiamondTestMom, public DiamondTestDad {
public:
	DiamondTestSon() : DiamondTestMom(), DiamondTestDad() {}
	~DiamondTestSon() {}
};

void diamond_inheritance_test() {

	DiamondTestDad dad;
	DiamondTestMom mom;
	DiamondTestSon son;

	dad.show_dads();
	mom.show_moms();
	son.show_dads();
	son.show_moms();
	son.show_humans();

}
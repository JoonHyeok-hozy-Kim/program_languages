#include <iostream>

class StaticTestClass {
	static int static_test_class_cnt;	// static variable

	int a;
	int b;
	const int c;	// const's value can only be assigned with initializer list

public:
	StaticTestClass();
	StaticTestClass(int input_b);
	StaticTestClass(int input_b, int input_c); // const allocation example

	void show_status();

	~StaticTestClass() { static_test_class_cnt--; };	// Recall the destructor
};

int StaticTestClass::static_test_class_cnt = 0;	// static variable initialization!

// initializer list example 1
StaticTestClass::StaticTestClass()
	: a(10), b(20), c(30) {	static_test_class_cnt++; }

// initializer list example 2
StaticTestClass::StaticTestClass(int input_b)
	: a(20), b(input_b), c(30) { static_test_class_cnt++; }

// initializer list, assigning input variable to const variable example
StaticTestClass::StaticTestClass(int input_b, int input_c)
	: a(20), b(input_b), c(input_c) { static_test_class_cnt++; }

void StaticTestClass::show_status() {
	std::cout << "\na : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "Total class0404 number : " << static_test_class_cnt << std::endl;
}


void initializer_list_and_const_test() {
	StaticTestClass a;
	a.show_status();

	StaticTestClass b(99);
	b.show_status();

	StaticTestClass c(1000, 2000);
	c.show_status();

	c.~StaticTestClass();		// Destruction and static variable check.
	b.show_status();
}


class ThisTestClass {
	int hp;
	int damage;
	bool is_dead;

public:
	ThisTestClass();
	ThisTestClass(int hp, int damage);

	int attack();
	ThisTestClass& get_damaged(int damage);
	void show_status();
};

ThisTestClass::ThisTestClass()
	:hp(1000), damage(10), is_dead(false) {}

ThisTestClass::ThisTestClass(int hp, int damage)
	:hp(hp), damage(damage), is_dead(false) {}

int ThisTestClass::attack() { return damage; }

ThisTestClass& ThisTestClass::get_damaged(int damage) {
	hp -= damage;
	if (hp <= 0) {
		is_dead = true;
		hp = 0;
	}	
	return *this;
}

void ThisTestClass::show_status() {
	std::cout << "\nHP : " << hp << std::endl;
	std::cout << "damage : " << damage << std::endl;
	std::cout << "dead : " << is_dead << std::endl;
}


void this_test() {
	ThisTestClass a;
	a.show_status();
	ThisTestClass b(20000, 20);
	b.show_status();

	b.get_damaged(a.attack());
	a.show_status();
	b.show_status();

	a.get_damaged(b.attack());
	a.show_status();
	b.show_status();
}


class RefReturn {
	int x;

public:
	RefReturn(int x) : x(x) {}
	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << "x : " << x << std::endl; }
};

void ref_return_test() {
	RefReturn a(20);
	a.show_x();

	int& b = a.access_x();
	b = 19;
	a.show_x();

	int c = a.access_x();
	c = 18;
	a.show_x();

	int d = a.get_x();
	d = 17;
	a.show_x();
}


class ConstFuncTest {
	int a;
	const int b;

public:
	ConstFuncTest(int a, int b) : a(a), b(b) {}
	void show_status() const { 
		std::cout << "\na : " << a << std::endl;
		std::cout << "b : " << b << std::endl;
	}
};

void const_function_test() {
	ConstFuncTest a(10, 20);
	a.show_status();
}
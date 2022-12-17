#include "05_02_operator_overloading_advanced.h"
#include "05_01_operator_overloading.h"
#include <iostream>
#include <cstring>
#include "04_05_custom_string_class.h"


/* Friend Class and Friend Fuction */
class FriendTestClass {
private:
	int private_var = 3;
	void private_method() { std::cout << "FriendTestClass's private_method" << std::endl; }

public:
	// Friend Class
	friend class MyFriendClass;
	
	// Friend Function
	friend void my_friend_function();

};

// Friend Class Definition
class MyFriendClass {
public:
	void friend_connection() {
		FriendTestClass old_friend;
		std::cout << old_friend.private_var << std::endl;
		old_friend.private_method();
	}
};

// Friend Fuction Definition
void my_friend_function() {
	FriendTestClass old_friend;
	std::cout << old_friend.private_var << std::endl;
	old_friend.private_method();
	return;
}


void friend_class_and_function_test() {
	MyFriendClass new_friend;
	new_friend.friend_connection();

	my_friend_function();
}


void binary_operator_overloading_test() {
	Complex a(0, 0);
	a.println();
	a = a + "12+34i";
	a.println();

	a = "12+34i" + a;
	a.println();
}


/////////////////////////////////////////////////////
/* Input/Output Operator Overloading */
/* The syntax "std::cout <<" was possible because "<<" operator was implemented in std::cout object. 
   If you check the <iostream>'s header file, you may find ostream's following operator definitions.

	ostream& operator<<(bool val);
	ostream& operator<<(short val);
	ostream& operator<<(unsigned short val);
	ostream& operator<<(int val);
	ostream& operator<<(unsigned int val);
	ostream& operator<<(long val);
	ostream& operator<<(unsigned long val);
	ostream& operator<<(float val);
	ostream& operator<<(double val);
	ostream& operator<<(long double val);
	ostream& operator<<(void* val);

   We can customize these output operator in our own classes.
 */

class IOStreamTestClass {
private:
	int x = 10;
	int y = 20;
public:
	friend std::ostream& operator<<(std::ostream& os, const IOStreamTestClass& i);
};

std::ostream& operator<<(std::ostream& os, const IOStreamTestClass& i) {
	os << "( " << i.x << ", " << i.y << " )";
	return os;
}


void iostream_operator_overloading_test() {
	IOStreamTestClass i;
	std::cout << i << std::endl;
}


/////////////////////////////////////////////////////
/* Subscript Operator Overloading */
char& MyString::operator[](const int index) { return string_content[index]; }

void subscript_operator_overloading_test() {
	MyString str("abc");
	str.println();
	std::cout << str[2] << std::endl;
}


/////////////////////////////////////////////////////
/* Wrapper Class */
/* - goal : the packaging, or to bound an object. */
class Int {
	int data;

public:
	Int(int num) : data(num) {}
	Int(const Int& i) : data(i.data) {}

	operator int() { return data; }		// This syntax allows the compliler to interpret Int class as int data type!
};

void wrapper_int_class_test() {
	Int i1(12);
	Int i2(13);

	std::cout << i1 + i2 << std::endl;
}


/////////////////////////////////////////////////////
/* Increment/Decrement operator */
/* 1. pre-{ } operator should return it self. */
/* 2. post-{ } operator should return the object before the incrementation/derementation. */

class IncrementTestClass {
	int data;

public:
	IncrementTestClass(int num) : data(num) {}
	IncrementTestClass(const IncrementTestClass& i) : data(i.data) {}

	// pre-increment operator overloading
	IncrementTestClass& operator++() {
		std::cout << "pre-increment : " << data;
		data++;
		std::cout << " -> " << data << std::endl;
		return *this;
	}

	// post-increment operator overloading
	IncrementTestClass operator++(int x) {
		std::cout << "post-increment : (this) " << data;
		IncrementTestClass temp(*this);
		std::cout << " (temp) " << temp.data;
		data++;
		std::cout << " -> (this) " << data;
		std::cout << " (temp) " << temp.data << std::endl;
		return temp;
	}
};


void increment_operators_overloading_test() {
	IncrementTestClass i(13);
	++i;
	i++;
}
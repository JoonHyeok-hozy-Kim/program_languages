#include "14_01_callables.h"
#include <iostream>
#include <functional>
#include <string>
using namespace std;


/* Def.) Callable in C++ : Anything we can call using () signs.
*/

/* Tech.) std::function : an object that can contain any callable
*/


namespace CallablesTest {
	int some_func1(const string& s) {
		cout << "func1 called : " << s << endl;
		return 0;
	}

	struct S {
		void operator()(char c) {
			cout << "func2 called : " << c << endl;
		}
	};

	void callables_function_test() {
		function<int(const string&)> f1 = some_func1;
		function<void(char)> f2 = S();
		function<void()> f3 = []() { cout << "func3 called" << endl; };		// Recall lamda fuction!

		f1("hello");
		f2('C');
		f3();
	}
}

void callables_function_test() {
	CallablesTest::callables_function_test();
}

/* Tech.) std::function for a member function of a class.
	- Get the reference of the target class and call the function member of it.
*/

namespace FunctionMemberFunctionTest {
	class A {
		int c;
	public:
		A(int c) : c(c) {}

		int some_func1() {
			cout << "some_func1 called. " << ++c << endl;
			return 0;
		}

		int some_func2() const {
			cout << "some_func2 called. " << c << endl;
			return 0;
		}

		static void st() {}
	};

	void test() {
		A a(10);
		function<int(A&)> f1 = &A::some_func1;
		function<int(const A&)> f2 = &A::some_func2;

		f1(a);
		f2(a);
		f1(a);
		f2(a);
	}
}

void callables_member_function_test() {
	FunctionMemberFunctionTest::test();
}


/* Concept) std::mem_fn : transforms a given member fucntion into a function object!
	- Check the below example of creating a vector that shows the length of each vector cotained in a vector.
	- std::transform : It automatically iterates the input and output iterator and inserts the proper item pre-defined by "UnaryOperation".
*/


#include <vector>
#include <algorithm>
void callables_mem_fn_vector_test() {
	vector<int> a(1);
	vector<int> b(2);
	vector<int> c(3);
	vector<int> d(4);

	// Case 1. When not using std::mem_fn
	cout << "Trial 1 : without mem_fn" << endl;
	vector<vector<int>> container1;
	container1.push_back(a);
	container1.push_back(b);
	container1.push_back(c);
	container1.push_back(d);

	// A custom function that returns the function object of the member fucntion of vector class, size(), should be prepared.
	function<size_t(const vector<int>&)> custom_size_func = &vector<int>::size;	

	vector<int> size_vec1(4);
	transform(container1.begin(), container1.end(), size_vec1.begin(), custom_size_func);
	for (auto itr = size_vec1.begin(); itr != size_vec1.end(); itr++) {
		cout << "Vector size : " << *itr << endl;
	}


	// Case 2. When using std::mem_fn
	cout << "Trial 2 : with mem_fn" << endl;
	vector<vector<int>> container2;
	container2.push_back(a);
	container2.push_back(b);
	container2.push_back(c);
	container2.push_back(d);

	vector<int> size_vec2(4);
	transform(container2.begin(), container2.end(), size_vec2.begin(), mem_fn(&vector<int>::size));
	for (auto itr = size_vec2.begin(); itr != size_vec2.end(); itr++) {
		cout << "Vector size : " << *itr << endl;
	}
}


namespace BindTest {
	void add(int a, int b) {
		cout << a << " + " << b << " = " << a + b << endl;
	}

	void subtract(int a, int b) {
		cout << a << " - " << b << " = " << a - b << endl;
	}

	void simple_bind_test() {
		auto add_with_2 = bind(add, 2, placeholders::_1);
		add_with_2(3); // equal to "add(3, 2);"

		add_with_2(3, 4); // equal to "add(3, 2);" and 4 is ignored.

		auto subtract_2 = bind(subtract, placeholders::_1, 2);
		subtract_2(5); // equal to "subtract(5, 2);"

		auto negate = bind(subtract, placeholders::_2, placeholders::_1);
		negate(5, 2);	// equal to "subtract(2, 5);"
	}


	struct S {
		int data;
	public:
		S(int a) : data(a) { cout << "regular constructor." << endl; };

		S(const S& s) { 
			cout << "copy constructor." << endl; 
			data = s.data;
		};

		S(S&& s) {
			cout << "move constructor." << endl;
			data = s.data;
		}
	};

	void do_sth(S& s1, const S& s2) { s1.data = s2.data + 3; }

	void reference_input_function_test() {
		S s1(1), s2(2);

		cout << "Case 1. Not properly working!" << endl;
		cout << "Before : " << s1.data << std::endl;
		auto do_sth_with_s1_one = bind(do_sth, s1, placeholders::_1);
		do_sth_with_s1_one(s2);
		cout << "After : " << s1.data << std::endl;

		cout << "Case 2. Use ref(). -> Properly working!" << endl;
		cout << "Before : " << s1.data << std::endl;
		auto do_sth_with_s1_two = bind(do_sth, ref(s1), placeholders::_1);
		do_sth_with_s1_two(s2);
		cout << "After : " << s1.data << std::endl;
	}
}

void callables_simple_bind_test() {
	BindTest::simple_bind_test();
}


void callables_ref_bind_test() {
	BindTest::reference_input_function_test();
}
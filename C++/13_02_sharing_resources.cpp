#include "13_02_sharing_resources.h"
#include <iostream>
#include <memory>
#include <vector>


/* Concept) shared_ptr
	- Consider the case that certain pointer object should be pointed by multiple objects.
	- If such pointer object counts the objects that are pointing at it, it can be destructed when all of those objects are deleted.
	- shared_ptr can work like that.
*/

using namespace std;

namespace SharedPtrTest {
	class A {
		int *data;

	public:
		A() {
			data = new int[100];
			cout << "Resource gained." << endl;
		}

		~A() {
			cout << "Destructor called" << endl;
			delete[] data;
		}
	};

	void shared_ptr_initial_test() {
		vector<shared_ptr<A>> vec;

		vec.push_back(make_shared<A>());	// Create a shared pointer using std::make_shared
		vec.push_back(shared_ptr<A>(vec[0]));
		vec.push_back(shared_ptr<A>(vec[1]));

		cout << "Erase from vec 1 (use_count : " << vec.begin()->use_count() << ")" << endl;	// Check the number of objects pointing at shared_ptr using use_count()
		vec.erase(vec.begin());
		cout << "Erase from vec 2 (use_count : " << vec.begin()->use_count() << ")" << endl;
		vec.erase(vec.begin());
		cout << "Erase from vec 3 (use_count : " << vec.begin()->use_count() << ")" << endl;
		vec.erase(vec.begin());

		cout << "END of program." << endl;
	}
}

void shared_ptr_initial_test() {
	SharedPtrTest::shared_ptr_initial_test();
}



/* Tech.) How to create a class that generates shared_ptr using "this" keyword : Inherit "enable_shared_from_this."
*/

namespace EnableSharedFromThis {
	class A : public enable_shared_from_this<A> {	// Inherit enable_shared_from_this!
		int* data;

	public:
		A() {
			data = new int[100];
			cout << "Resource gained." << endl;
		}

		~A() {
			cout << "Destructed." << endl;
			delete[] data;
		}

		shared_ptr<A> get_shared_ptr() { return shared_from_this(); }
	};

	void shared_ptr_enable_shared_from_this_test() {
		shared_ptr<A> pa1 = make_shared<A>();
		cout << pa1.use_count() << endl;

		shared_ptr<A> pa2 = pa1->get_shared_ptr();	// Making shared_ptr of itself.
		cout << pa1.use_count() << endl;
		cout << pa2.use_count() << endl;
	}
}

void shared_ptr_enable_shared_from_this_test() {
	EnableSharedFromThis::shared_ptr_enable_shared_from_this_test();
}


/* Warning : Circular Reference
	- Consider the case when two shared_ptrs are pointing at each other.
	- Then, neither of them can be destructed since the count never decreases.
	- Check the below example.
	- Solution : weak_ptr
*/

namespace CircularRefereceTest {
	class A : public SharedPtrTest::A {
		shared_ptr<A> other;

	public:
		A() : SharedPtrTest::A() {}
		~A() {}
		void set_other(shared_ptr<A> o) { other = o; }
	};

	void share_ptr_circular_referece_test() {
		shared_ptr<A> pa = make_shared<A>();
		shared_ptr<A> pb = make_shared<A>();

		pa->set_other(pb);
		pb->set_other(pa);
	}
}

// Check that destructors are not called!
void share_ptr_circular_referece_test() {
	CircularRefereceTest::share_ptr_circular_referece_test();
}


/* Concept) weak_ptr
	- It prevents the possible memory leak just like shared_ptr.
	- However, it does not increase the count of the objects that points at it like a shared_ptr.
*/


namespace WeakPtrTest {
	class A {
		string s;
		weak_ptr<A> other;

	public:
		A(const string& s) : s(s) { cout << "Resource gained!" << endl; }
		~A() { cout << "Destructor called." << endl; }

		string name() { return s; }
		void set_other(weak_ptr<A> o) { other = o; }
		void access_other() {
			shared_ptr<A> o = other.lock();	// Convert weak_ptr into shared_ptr when used!
			if (o) {
				cout << "Access : " << o->name() << endl;
			}
			else {	// If the object that the weak_ptr points at is destructed, lock() returns null.
				cout << "Already destructed." << endl;
			}
		}
	};

	void weak_ptr_test() {
		vector<shared_ptr<A>> vec;
		vec.push_back(make_shared<A>("R1"));
		vec.push_back(make_shared<A>("R2"));

		// Repeat the circular reference problem using weak_ptr.
		vec[0]->set_other(vec[1]);
		vec[1]->set_other(vec[0]);

		cout << "vec[0] ref count : " << vec[0].use_count() << endl;
		cout << "vec[1] ref count : " << vec[1].use_count() << endl;

		vec[0]->access_other();

		vec.pop_back();
		vec[0]->access_other();
	}
}

void sharing_resources_weak_ptr_test() {
	WeakPtrTest::weak_ptr_test();
}
#include "10_01_stl_vector_list_deque.h"

template <typename T>
void print_vector(std::vector<T> vec) {
	std::cout << "[";
	/* "typename" keyword is required because iterator is a dependent type. */
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		std::cout << *itr;
		if (itr != vec.end()-1) std::cout << ", ";
	}
	std::cout << "]\n";
}

void stl_vector_test() {
	std::vector<int> v1;
	int n = 20;
	for (int i = 0; i < n; i++) {
		v1.push_back(i + 1);
		// size() returns amortized size of the vector in type size_t
		//std::cout << i+1 << "-th insertion, size : " << v1.size() << std::endl;
		print_vector(v1);
	}
	for (int i = 0; i < n; i++) {
		/* [] operator */
		//std::cout << v1[i] << std::endl;
		
		/* pop_back() */
		//std::cout << v1[v1.size() - 1] << std::endl;
		//v1.pop_back();
	}

	/* iterator */
	for (std::vector<int>::iterator itr = v1.begin(); itr != v1.end(); ++itr) {
		std::cout << *itr << std::endl;
	}

	/* insert method */
	v1.insert(v1.begin() + 2, -99);
	print_vector(v1);

	/* erase method */
	v1.erase(v1.end() - 3);
	print_vector(v1);

	/* Concept) const iterator : const pointer for a certain iteration. 
								 Cannot change the value. */
	std::vector<int>::iterator ci1 = v1.begin() + 3;
	auto ci2 = v1.begin() + 3;
	std::cout << typeid(ci1).name() << " / " << std::endl;
	std::cout << typeid(ci2).name() << std::endl;

	/* Concept) reverse iterator */
	// Application : reverse print!
	for (std::vector<int>::reverse_iterator itr = v1.rbegin(); itr != v1.rend(); itr++) {
		std::cout << *itr << ", ";
	}

}

///////////////////////////////////////////////////////////////////////
/* Concept) range based for loop */
void range_based_for_loop_test() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (int elem : v) {
		std::cout << "Element : " << elem << std::endl;
	}

	// Using auto keyword
	for (const auto& elem : v) {
		std::cout << "Element : " << elem << std::endl;
	}
}

///////////////////////////////////////////////////////////////////////
/* Tech) list container */
/*  - positional linked list structure that [] operators are not implemented */

template <typename T>
void print_list(std::list<T> list) {
	std::cout << "[";
	for (typename std::list<T>::iterator itr = list.begin(); itr != list.end(); itr++) {
		std::cout << *itr;
		std::cout << " ";
		//if (itr != list.end()-1) std::cout << ", ";
	}
	std::cout << "]\n";
}

void stl_list_test() {
	std::list<int> l;
	for (int i = 0; i < 10; i++) l.push_back(i);
	print_list(l);

	/* Insert at certain position */
	for (std::list<int>::iterator itr = l.begin(); itr != l.end(); ++itr) {
		if (*itr == 5) {
			l.insert(itr, 100);
			break;
		}
	}
	print_list(l);

	/* Erase at certain position */
	for (std::list<int>::iterator itr = l.begin(); itr != l.end(); ++itr) {
		if (*itr == 100) {
			l.erase(itr);
			break;
		}
	}
	print_list(l);
}

///////////////////////////////////////////////////////////////////////
/* Tech) deque container */
/*  - modification allowed only at the beginning or at the end. */
template <typename T>
void print_deque(std::deque<T> deque) {
	std::cout << "[";
	for (typename std::deque<T>::iterator itr = deque.begin(); itr != deque.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << "]\n";
}

void stl_deque_test() {
	std::deque<int> d;
	for (int i = 0; i < 5; i++) d.push_back(i);
	print_deque(d);
	for (int i = 0; i < 5; i++) d.push_front(i * (-1));
	print_deque(d);

	d.pop_back();
	print_deque(d);
	d.pop_front();
	print_deque(d);
}

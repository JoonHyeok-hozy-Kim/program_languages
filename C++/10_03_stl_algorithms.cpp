#include "10_03_stl_algorithms.h"


template <typename Iter>
void iter_vector_print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}


/* Sorting provided by STL */
void vector_sort_test() {

	std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(6);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(2);

	iter_vector_print(v1.begin(), v1.end());
	
	// Sort!
	std::sort(v1.begin(), v1.end());

	iter_vector_print(v1.begin(), v1.end());

}


/* How to sort in the reverse order. 
	1. Define a functor that indicates to rule.
	2. Call that functor as an input parameter for sort
*/

// Functor for the decreasing order : Any type that supports operator< is applicable.
template <typename T>
struct int_compare {
	bool operator()(const T& a, const T& b) const { return a > b; }
};

void vector_reverse_sort_test() {

	std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(6);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(2);

	iter_vector_print(v1.begin(), v1.end());

	// Reverse Sort!
	std::sort(v1.begin(), v1.end(), int_compare<int>());

	iter_vector_print(v1.begin(), v1.end());
}


//////////////////////////////////////////////////////////////
/* Partial Sort 
	- Get three input parameters : start, middle, end.
	- Sort elements between start and middle.
*/
void partial_sort_test() {

	std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(6);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(2);

	iter_vector_print(v1.begin(), v1.end());

	// Partial Sort
	std::partial_sort(v1.begin(), v1.begin() + 4, v1.end());

	iter_vector_print(v1.begin(), v1.end());
}


//////////////////////////////////////////////////////////////
/* Stable Sort
	- Keep original sequence after sorting.
*/
struct ClassForStableSortTest {
	std::string str;
	int num;

	ClassForStableSortTest(std::string str, int num) : str(str), num(num) {};
	bool operator<(const ClassForStableSortTest& c) const { return num < c.num; }	// operator < for comparison
};

std::ostream& operator<<(std::ostream& o, const ClassForStableSortTest& c) {
	o << "[" << c.str << "," << c.num << "]";
	return o;
}

void stable_sort_test() {
	std::vector<ClassForStableSortTest> v1;
	for (int i = 0; i < 100; i++) {
		std::string name = "";
		name.push_back('a' + i / 26);
		name.push_back('a' + i % 26);
		v1.push_back(ClassForStableSortTest(name, static_cast<int>(rand() & 10)));
	}

	std::vector<ClassForStableSortTest> v2 = v1;

	iter_vector_print(v1.begin(), v1.end());

	// Regular Sort.
	std::sort(v1.begin(), v1.end());
	iter_vector_print(v1.begin(), v1.end());

	// Stable Sort.
	std::stable_sort(v2.begin(), v2.end());
	iter_vector_print(v2.begin(), v2.end());

}
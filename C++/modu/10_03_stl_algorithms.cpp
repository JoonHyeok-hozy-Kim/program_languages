#include "10_03_stl_algorithms.h"


template <typename Iter>
void iter_vector_print(Iter begin, Iter end) {
	std::cout << "[";
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << "]" << std::endl;
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


//////////////////////////////////////////////////////////////
/* Remove Function for Iterables 
	- Although STL iterables support erase methods, they are inconvenient due to the initialization of iterators. (You should initialize iterator anytime erase is operated.)
	- STL remove moves the elements by certain rules and can be used with erase for convenience.
*/

// A functor that verifies if an element is odd
struct is_odd {
	bool operator()(const int& i) { return i % 2 == 1; }
};

struct gt_3 {
	bool operator()(const int& i) { return i > 3; }
};

void stl_remove_test() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	iter_vector_print(vec.begin(), vec.end());

	// remove : Remove certain elements that are equal to X
	std::cout << "remove : Remove certain elements that are equal to X : ";
	vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());		// remove : move all the elements that are equal to 3.
	iter_vector_print(vec.begin(), vec.end());

	// remove_if : Remove certain elements that satisfy a condition
	std::cout << "remove_if : Remove certain elements that satisfy a condition : ";
	vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());	// remove elements that are odd numbers.
	iter_vector_print(vec.begin(), vec.end());
}


// Ex.) More complicated conditions using functor and remove_if
struct stl_my_condition {
	int* count;		// Put counting variable out of the functor

	stl_my_condition(int* count) : count(count) {}

	bool operator()(const int& i) {
		if (*count >= 3) return false;	// remove maximum 2 elements

		if (i < 5) {					// remove if less than 5
			(*count)++;
			return true;
		}

		return false;
	}
};

void stl_custom_remove_test() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	iter_vector_print(vec.begin(), vec.end());

	std::cout << "Remove First two elements that are less than 5 : ";
	int delete_num = 0;
	vec.erase(std::remove_if(vec.begin(), vec.end(), stl_my_condition(&delete_num)), vec.end());
	iter_vector_print(vec.begin(), vec.end());
}


//////////////////////////////////////////////////////////////////////////
/* Lambda Function 
	- Recall that previous custom method is inconvenient on the point that functor's member values should stay outside the functor.
	- Lambda Function can be a perfect substitute.
*/

void stl_custom_lambda_remove_odd_number_test() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	iter_vector_print(vec.begin(), vec.end());

	std::cout << "Remove First two elements that are less than 5 : ";
	vec.erase(std::remove_if(vec.begin()
							,vec.end()
							,[](int i) -> bool { return i % 2 == 1; })	// Lambda Function! Syntax : [_capture_list_] (_input_type_ _input_var_) -> _return_type_ { _function_implementation_ }
			 ,vec.end());


	iter_vector_print(vec.begin(), vec.end());
}

void stl_custom_lambda_remove_first_two_num_less_than_5() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	iter_vector_print(vec.begin(), vec.end());

	std::cout << "Remove First two elements that are less than 5 : ";
	int num_erased = 0;
	vec.erase(std::remove_if(vec.begin()
							,vec.end()
							,[&num_erased](int i) -> bool { if (num_erased > 2) return false;
															 else if (i < 5) {
																 num_erased++;
																 return true;}
															return false; })	// Lambda Function! Syntax : [_capture_list_] (_input_type_ _input_var_) -> _return_type_ { _function_implementation_ }
			,vec.end());


	iter_vector_print(vec.begin(), vec.end());

}


//////////////////////////////////////////////////////////////////////////////////////////////////
/* transform : Change the values of an iterable
*/

void stl_transform_add_one_test() {
	std::vector<int> vec;
	for (int i = 0; i < 5; i++) vec.push_back(i);

	iter_vector_print(vec.begin(), vec.end());

	std::transform(vec.begin(), vec.end(), vec.begin(),
		[](int i) {return i + 1; });
	iter_vector_print(vec.begin(), vec.end());
}


////////////////////////////////////////////////////////////////////////////////////////////////
// Searching functions

// find function
void stl_find_function_test() {
	std::vector<int> vec;
	for (int i = 0; i < 5; i++) vec.push_back(i);
	vec.push_back(3);

	iter_vector_print(vec.begin(), vec.end());

	auto current = vec.begin();
	while (true) {
		current = std::find(current, vec.end(), 3);
		if (current == vec.end()) break;
		std::cout << "3 is " << std::distance(vec.begin(), current) + 1 << "-th element." << std::endl;
		current++;
	}
}
                                                      
void stl_find_if_function_test() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	auto current = vec.begin();
	while (true) {
		current =
			std::find_if(current, vec.end(), [](int i) { return i % 3 == 2; });
		if (current == vec.end()) break;
		std::cout << "3 으로 나눈 나머지가 2 인 원소는 : " << *current << " 이다 "
			<< std::endl;
		current++;
	}
}
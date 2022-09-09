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
								 Cannot change the value.
	*/
	std::vector<int>::iterator ci1 = v1.begin() + 3;
	auto ci2 = v1.begin() + 3;
	std::cout << typeid(ci1).name() << " / " << std::endl;
	std::cout << typeid(ci2).name() << std::endl;
}
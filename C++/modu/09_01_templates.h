#include <iostream>
#include <string>
#include <bitset>


/* Class Template Case */
namespace TemplateClasses {
	template <typename T>	// Define the template for the class below.
	class Vector {
		T* data;
		int capacity;
		int length;

	public:
		typedef T value_type;

		Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {};

		std::string str() {
			std::string s("[");
			for (int i = 0; i < length; i++) {
				if (typeid(std::string) == typeid(data[i])) s += data[i];
				else {
					//s.push_back(std::to_string(data[i]));
				}
				if (i < length - 1) s += ", ";
			}
			s += "]";
			return s;
		}

		void print() {
			std::cout << "[";
			for (int i = 0; i < length; i++) {
				std::cout << data[i];
				if (i < length - 1) std::cout << ", ";
			}
			std::cout << "]";
		}

		void println() {
			print();
			std::cout << std::endl;
		}

		void capacity_change(double times) {
			T* prev_data = data;
			capacity = (int)((double)capacity * times);
			//std::cout << "New capa : " << capacity << std::endl;
			if (capacity < length) {
				std::cout << "[Error] In Vector::capacity_change, capacity < length" << std::endl;
				return;
			}
			data = new T[capacity];
			for (int i = 0; i < length; i++) data[i] = prev_data[i];
			return;
		}

		void push_back(T s) {
			if (capacity == length) capacity_change(2);
			data[length] = s;
			length++;
		}

		T operator[](int i) { return data[i]; }

		void remove(int x) {
			if (length <= x) {
				std::cout << "[Error] In Vector::remove, length <= x" << std::endl;
				return;
			}
			if (x < length - 1) {
				for (int i = x; i < length - 1; i++) { data[i] = data[i + 1]; }
			}
			length--;
			if (length < capacity / 2) capacity_change(.5);
		}

		int size() { return length; }

		void swap(int x, int y) {
			if (!(x < length && y < length)) {
				std::cout << "[Error] Index out of range." << std::endl;
				return;
			}

			T temp = data[x];
			data[x] = data[y];
			data[y] = temp;
		}

		~Vector() { delete[] data; }
	};


	/* Template Specialization */
	/* Customization for specific type of instance */
	/* Ex.) special TemplateVector class for bool data type */
	template <>
	class Vector<bool> {
		unsigned int* data;		// total 32(=4*8) bools will be assinged to each 4-Byte unsigned int data type.
		int capacity;
		int length;

	public:
		typedef bool value_type;

		Vector(int n = 1)
			: data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) { 	// Recall that 32 bools for each unsigned int.
			for (int i = 0; i < capacity; i++) {
				data[i] = 0;
			}
		};

		std::string str() {
			std::string s("[");
			for (int i = 0; i < length; i++) {
				bool temp = ((data[i / 32] & (1 << (i % 32))) != 0);
				s.append(std::to_string(temp));
				if (i < length - 1) s.append(", ");
			}
			s += "]";
			return s;
		}

		void print() {
			std::cout << str() << std::endl;
		}

		void capacity_change(double times) {
			unsigned int* prev_data = data;
			int prev_capacity = capacity;
			capacity = (int)((double)capacity * times);
			//std::cout << "New capa : " << capacity << std::endl;
			if (capacity < length / 32) {
				std::cout << "[Error] In Vector::capacity_change, capacity < length" << std::endl;
				return;
			}
			data = new unsigned int[capacity];
			for (int i = 0; i < capacity; i++) {
				if (i < prev_capacity) data[i] = prev_data[i];
				else data[i] = 0;
			}
			delete prev_data;
			return;
		}

		void push_back(bool s) {
			if (capacity == length / 32) capacity_change(2);
			//std::cout << "prev : " << data[length / 32] << " / d : " << (1 << (length % 32)) << std::endl;
			if (s) {
				data[length / 32] |= (1 << (length % 32));	// Make specific digit into 1 if true. ( 1|0 == 1|1 == 1 )
			}
			//std::cout << " -> " << data[length / 32] << std::endl;
			length++;
		}

		bool operator[](int i) {
			return ((data[i / 32] & (1 << (i % 32))) != 0);
		}

		void remove(int x) {
			if (length <= x) {
				std::cout << "[Error] In Vector::remove, length <= x" << std::endl;
				return;
			}

			int last = length - 1;
			if (x < last) {
				for (int i = x; i < last; i++) {
					int j = i + 1;
					// When next digit is 1
					if (data[j / 32] & (1 << (j % 32))) data[i / 32] |= (1 << (i % 32));
					// When next digit is 0
					else {
						// When current digit is 1
						if (data[i / 32] & (1 << i % 32)) {
							data[i / 32] ^= (1 << (i % 32));	// Use XOR operator : 1 ^ 1 = 0
						}
					}
					//std::cout << "In loop, " << str() << std::endl;
				}
			}

			// If prev last digit is 1,
			if (data[last / 32] & (1 << last % 32)) {
				data[last / 32] ^= (1 << (last % 32));	// Use XOR operator : 1 ^ 1 = 0
				//std::cout << "Out loop, " << str() << std::endl;
			}
			length--;
			//std::cout << "Final, " << str() << std::endl;
			if (length < capacity / 2) capacity_change(.5);
		}

		int size() { return length; }

		~Vector() { delete[] data; }
	};
}


void template_vector_test();
void bool_vector_test();


/////////////////////////////////////////////////////////////
// Function Template 
// Ex1.) max function template
template <typename T>
T max(T& a, T& b) {
	return a > b ? a : b;	// Recall the ternary operator, "x ? y : z" == "If x return y, else return z"
}

void function_template_max_test();
void swap_function_test();

// Ex2.) bubble sort
// A class that wants to call this template should posses size() and swap() as members.
template <typename Container>
void bubble_sort(Container& cont) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i + 1; j < cont.size(); j++) {
			if (cont[i] > cont[j]) cont.swap(i, j);
		}
	}
}

void bubble_sort_test();


//////////////////////////////////////////////////////
// Tech.) Function Object (Functor)
// Functor : an object that operates like function but actually not the real function
// Ex.) Let's build the reverse bubble_sort using Functor

// Override bubble_sort function
template <typename Container, typename Comparison>
void bubble_sort(Container& cont, Comparison& comp) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i + 1; j < cont.size(); j++) {
			if (!comp(cont[i], cont[j])) {	// Custom comparison functor used : use CompGT or CompLT
				cont.swap(i, j);
			}
		}
	}
}

// Functor 1 : comparison greater than
struct CompGT {
	bool operator()(int a, int b) { return a > b; };
	bool operator()(std::string a, std::string b) { return a > b; };
};
// Functor 2 : comparison lesser than
struct CompLT {
	bool operator()(int a, int b) { return a < b; }
	bool operator()(std::string a, std::string b) { return a < b; };
};

void bubble_sort_reverse_test();


//////////////////////////////////////////////////
// Concept) non-type template arguments
// template's input parameter that is not a type
// Ex.) a template that receives an integer
template <typename TYPE, int num>
TYPE add_num(TYPE type) {
	return type + num;
}

void non_type_template_argument_test();


// Tech.) Setting default for the non-type template arguments
template <typename TYPE, int num=5>
TYPE add_num_with_default(TYPE type) {
	return type + num;
}

void non_type_template_argument_default_test();



// Ex2.) std::array class that uses non-type template arguments
#include <array>
void non_type_template_argument_array_test();

// Each std::array definitions are actually types.
// Thus, if you want to call them in a function, you should use the reference.
template <typename ARRAY_TYPE>
void print_array(const ARRAY_TYPE& arr) {
	std::cout << "[";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
		if (i < arr.size() - 1) std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void print_array_test();

namespace TestSpace {
	class Vector {
		int a;

	public:
		Vector(int a) : a(a) {};
		void print() { std::cout << a << std::endl; }
	};
}

void test_space_test();
#include "16_01_uniform_initialization.h"


/* Concept) Uniform Initialization
	- Why adopted?
		- () operators are used for both object constructions and function constructions.
		- In order to avoid the ambiguity, use {} only for the object constructions!
*/

#include <iostream>

namespace UniInitTest1 {
	class A {
	public:
		A() { std::cout << "A's constructor" << std::endl; }
	};

	void test() {
		std::cout << "Case 1. () using case" << std::endl;
		A a1();	// Compiler interprets it as "Defining a new function a that returns A datatype."
		std::cout << "Case 1 ended." << std::endl;

		std::cout << "Case 2. Uniform initialization case" << std::endl;
		A a2{};
		std::cout << "Case 2 ended." << std::endl;
	}
}

void uniform_initialization_simple_test() {
	UniInitTest1::test();
}


// Prop.) Uniform Initialization does not allow narrow-conversion
namespace UniInitTest2 {
	class A {
	public:
		A(int x) { std::cout << "A constructed, x : " << x << std::endl; }
	};

	void test() {
		A a{ 1 };	// Proper definition
		A c(1.1);	// Ordinary initialization allows narrow-conversion
		//A b{ 1.1 }; // Uniform Initialization does NOT allow narrow-conversion
	}
}

void uniform_initialization_narrow_conversion_test() {
	UniInitTest2::test();
}


// Prop.) When used for the function return, uniform initialization allows omission of the datatype!
namespace UniInitTest3 {
	class A {
	public:
		A(int x, double y) { std::cout << "A construction" << std::endl; }
	};

	A func_a() {
		return { 1, 3.3 };	// Datatype utterance omitted with uniform initialization!
	}

	void test() {
		func_a();
	}
}

void uniform_initialization_function_omit_test() {
	UniInitTest3::test();
}



/* Concept) Initializer List
	- A container that is automatically initialized!
*/
namespace InitListTest1 {
	class A {
	public:
		A(std::initializer_list<int> a) { 
			std::cout << "A constructed" << std::endl; 
			for (auto itr = a.begin(); itr != a.end(); itr++) {
				std::cout << *itr << " ";
			}
		}
	};

	void test() {
		A b = { 1,2,3,4,5 };
	}
}

void initializer_list_simple_test() {
	InitListTest1::test();
}

/* Tech.) Declaration using initializer list for vector and map class
*/
#include <vector>
#include <map>
#include <string>
namespace InitListTest2 {
	template <typename T>
	void print_vector(const std::vector<T>& v) {
		std::cout << "[ ";
		for (const auto& e : v) {
			std::cout << e << " ";
		}
		std::cout << "]" << std::endl;
	}

	void vector_test() {
		std::vector<int> v = { 1,2,3,4,5 };
		print_vector(v);
	}

	template<typename K, typename V>
	void print_map(const std::map<K, V>& m) {
		for (const auto& kv : m) {
			std::cout << kv.first << " - " << kv.second << std::endl;
		}
	}

	void map_test() {
		std::map<std::string, int> m = {
			{"abc", 1},
			{"def", 2},
			{"ghi", 3}
		};

		print_map(m);
	}
}

void initializer_list_vector_map_test() {
	InitListTest2::vector_test();
	InitListTest2::map_test();
}


/* Tech.) initializer list and auto
	- Initializer automatically defines the datatype of the linitializer_list
*/
namespace InitListTest3 {
	void test() {
		auto a = { 1 };		// initializer_list<int>
		auto b{ 1 };		// int
		auto c = { 1,2 };	// initializer_list<int>
		//auto c{ 1,2 };		// WRONG! 
	}

	using namespace std::literals;
	void string_test() {
		auto a = { "a", "b", "c" };		// const *char
		auto b = { "a"s, "b"s, "c"s };	// std::string
	}
}

void initializer_list_and_auto() {
	InitListTest3::test();
	InitListTest3::string_test();
}
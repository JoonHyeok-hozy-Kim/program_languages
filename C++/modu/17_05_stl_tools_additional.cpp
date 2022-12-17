#include "17_05_stl_tools_additional.h"


/* Tech.) std::optional 
	- A class that OPTIONALLY contains the intended value.
	- This class does not operate dynamic allocation until the actual value is allocated.
		-> Thus, much faster compared to codes that do not use this, but has to define variable that conditionally contains value.
	- Check the map example below!
*/

#include <iostream>
#include <map>
#include <string>
#include <optional>

namespace OptionalInMapExample {

	std::map<int, std::string> data = { {1, "hi"}, {2, "hello"}, {3, "hiroo"} };

	// Solution 1.) Return empty string instance.
	std::string empty_string_return_solution(const std::map<int, std::string>& m, int key) {
		auto itr = m.find(key);
		if (itr != m.end()) {
			return itr->second;
		}
		return std::string();	// Return empty string if not found.
								// Problem : What if the actual value is empty string? Can we differentiate it from the non-existing case?
								//			 What if the second value of the map is not std::string type? 
								//           Should we define the default value every time the value type is changed?
	}


	// Solution 2.) Using pair that specifies the existing and non-existing cases.
	std::pair<std::string, bool>  pair_using_solution(const std::map<int, std::string>& m, int key) {
		auto itr = m.find(key);
		if (itr != m.end()) {
			return std::make_pair(itr->second, true);
		}
		return std::make_pair(std::string(), false);	// Return pair that contains the default value empty string.
														// Problem : Is default empty string necessary?
														//           What if the instanciation and allocation of the default value takes resources and lowers the performance of the program.
	}


	// Solution 3) Use std::optional.
	std::optional<std::string> optional_using_solution(const std::map<int, std::string>& m, int key) {
		auto itr = m.find(key);
		if (itr != m.end()) {
			return itr->second;
		}

		return std::nullopt;	// Return nullopt. -> No instantiation of a default object.
	}


	void test() {

		std::cout << "\nTest Case 1 : Return empty string instance." << std::endl;
		std::cout << "  In map, 2 -> " << empty_string_return_solution(data, 2) << std::endl;
		std::cout << "  In map, 4 -> " << empty_string_return_solution(data, 4) << std::endl;

		std::cout << "\nTest Case 2 : Use pair that specifies the existing and non-existing cases." << std::endl;
		std::cout << "  In map, 2 -> " << pair_using_solution(data, 2).second << std::endl;
		std::cout << "  In map, 4 -> " << pair_using_solution(data, 4).second << std::endl;

		std::cout << "\nTest Case 3 : Use std::optional." << std::endl;
		std::optional<std::string> o1 = optional_using_solution(data, 2);
		std::optional<std::string> o2 = optional_using_solution(data, 4);
		std::cout << "  In map, 2 -> ";
		if (o1)	std::cout << o1.value() << std::endl;
		std::cout << "  In map, 4 -> ";
		if (o2)	std::cout << o2.value() << std::endl;
	}
}

void optional_comparison_test() {
	OptionalInMapExample::test();
}


/* Tech.) How to make optional object for a reference?
	- std::optional does not support reference object.
	- Instead, we can use std::reference_wrapper.
*/

namespace OptionalForReference {
	class A {
	public:
		int data;
	};

	void test() {
		A a;
		a.data = 5;

		std::optional<std::reference_wrapper<A>> maybe_a = std::ref(a);

		maybe_a->get().data = 3;
		std::cout << "a's data : " << a.data << std::endl;
	}
}

void optional_reference_test() {
	OptionalForReference::test();
}



/* Concept) std::variant 
	- One of varioius data types.
*/
#include <variant>

namespace VariantSimpleTest {
	void test() {
		std::variant<int, std::string, double> v1;

		v1 = 1;
		v1 = "abc";
		v1 = 1.1;
	}
}


void variant_simple_test() {
	VariantSimpleTest::test();
}


/* Tech.) Application of variant, compared to polymorphism.
	- Consider the case that a function should return two different classes depending on a condition.
	- One can use polymorphism or variant as a solution.
*/

#include <memory>

namespace VariantVSPoly {

	// Polymorphism solution : Common parent of A and B is needed!
	class PolyParent {
	public:
		virtual void a() {};
		virtual void b() {};
	};
	class PolyA : public PolyParent {
	public:
		void a() override { std::cout << "PolyA" << std::endl; };
	};
	class PolyB : public PolyParent {
	public:
		void b() override { std::cout << "PolyB" << std::endl; }
	};

	std::unique_ptr<PolyParent> polymorphism_solution(bool is_a) {
		if (is_a) return std::make_unique<PolyA>();
		return std::make_unique<PolyB>();
	}

	// Variant solution
	class VariantA {
	public:
		void a() { std::cout << "VariantA" << std::endl; }
	};
	class VariantB {
	public:
		void b() { std::cout << "VariantB" << std::endl; }
	};

	std::variant<VariantA, VariantB> variant_solution(bool is_a) {
		if (is_a) return VariantA();
		return VariantB();
	}


	void test() {
		auto poly_a = polymorphism_solution(true);
		poly_a->a();
		
		auto variant_a = variant_solution(true);
		std::get<VariantA>(variant_a).a();
	}

}

void variant_vs_polymorphism() {
	VariantVSPoly::test();
}


/* Tech.) std::monostate
	- Works like std::optional for std::variant
*/
namespace VariantMonostate {
	std::variant<std::monostate, int, std::string> a;	// Default is std::monostate!
}


/* Concept) std::tuple
	- A container that allows various data types!
*/

#include <tuple>
namespace TupleTest {
	void simple_test() {
		std::tuple<int, double, std::string> t1;
		t1 = std::make_tuple(1, 3.14, "pi");

		std::cout << std::get<0>(t1) << ", " << std::get<1>(t1) << ", "
			<< std::get<2>(t1) << std::endl;
	}

	void structured_binding_test() {
		std::tuple<int, double, std::string> t1;
		t1 = std::make_tuple(1, 3.14, "pi");

		auto [i, f, s] = t1;
		std::cout << i << ", " << f << ", " << s << std::endl;
	}
}

void tuple_simple_test() {
	TupleTest::simple_test();
}

void tuple_structured_binding_test() {
	TupleTest::structured_binding_test();
}
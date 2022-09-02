#include "09_01_templates.h"

void template_vector_test() {

	TemplateVector<int> ti;
	for (int i = 0; i < 10; i++) {
		ti.push_back(i);
		//ti.print();
		std::cout << ti[i] << std::endl;
	}

	TemplateVector<std::string> ts;
	for (int i = 0; i < 10; i++) {
		std::string s = "";
		s.push_back((char)(i + 65));
		ts.push_back(s);
		//ts.print();
		std::cout << ts[i] << std::endl;
	}
}

void bool_vector_test() {

	TemplateVector<bool> tb;
	for (int i = 0; i < 10; i++) {
		tb.push_back(i % 2);
		tb.print();
	}

	for (int i = 0; i < 10; i++) {
		tb.remove(0);
		tb.print();
	}

	for (int i = 1; i < 34; i++) {
		tb.push_back(i % 2);
		tb.print();
	}

	for (int i = 1; i < 34; i++) {
		tb.remove(tb.size()-1);
		tb.print();
	}
}

void function_template_max_test() {
	int a = 3;
	int b = 2;
	std::cout << max(a, b) << std::endl;

	char c = 'z';
	char d = 'y';
	std::cout << max(c, d) << std::endl;

	std::string e = "zoo";
	std::string f = "zebra";
	std::cout << max(e, f) << std::endl;
}

void swap_function_test() {
	TemplateVector<int> ti;
	for (int i = 0; i < 5; i++) ti.push_back(i);
	//ti.print();
	ti.swap(0, 3);
	ti.print();

	TemplateVector<std::string> ts;
	for (int i = 0; i < 5; i++) {
		std::string temp_str = "";
		temp_str.push_back('A' + i);
		ts.push_back(temp_str);
	}
	ts.print();
	ts.swap(0, 3);
	ts.print();
}

void bubble_sort_test() {
	TemplateVector<std::string> ti;
	ti.push_back("B");
	ti.push_back("A");
	ti.push_back("D");
	ti.print();
	bubble_sort(ti);
	ti.print();

}

void bubble_sort_reverse_test() {
	TemplateVector<std::string> ti;
	ti.push_back("B");
	ti.push_back("A");
	ti.push_back("K");
	ti.push_back("D");
	ti.print();

	CompGT comp_gt;		// Instanciate the Functor
	CompLT comp_lt;		// Instanciate the Functor

	bubble_sort(ti, comp_lt);
	ti.print();
	bubble_sort(ti, comp_gt);
	ti.print();


	TemplateVector<double> tii;
	tii.push_back(1.2);
	tii.push_back(3.8);
	tii.push_back(0.2);
	tii.push_back(99);
	tii.push_back(-12);
	tii.print();
	bubble_sort(tii, comp_gt);
	tii.print();
	bubble_sort(tii, comp_lt);
	tii.print();
}

void non_type_template_argument_test() {
	int x = 10;
	std::cout << add_num<int, 5>(x) << std::endl;
}

void non_type_template_argument_default_test() {
	int x = 10;
	std::cout << add_num_with_default<int>(x) << std::endl;
}

void non_type_template_argument_array_test() {
	std::array<int, 5> a = { 1,2,3,4,5 };
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << " ";
	}
}

void print_array_test() {

	std::array<int, 5> a = { 1,2,3,4,5 };
	std::array<int, 3> b = { 3,4,5 };

	print_array(a);
	print_array(b);
}
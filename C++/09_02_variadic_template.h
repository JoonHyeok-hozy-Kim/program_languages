#include <iostream>
#include <string>

/* Concept) Variadic Template
/*	Def.) A template that can recieve the arbitrary number of parameters.
/*	Ex.) Python's print() function : print(1,'a',3.3)
/*	
/*	Def.) Parameter Pack : a pack of parameters which are the input parameters for a variadic template
*/

// Ex1.) C++ implement of print() function in Python
template <typename T>
void variadic_template_print(T arg) {		// This function works as the final execution of the recursive structure!
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>	// Parameter Pack using "..." expression
void variadic_template_print(T arg, Types... args) {
	std::cout << arg << ", ";
	variadic_template_print(args...);		// Recursively runs the function with the remaining pararmeters
}

void variadic_template_print_test();



// Ex2.) Concatenating multiple string instances.
/* The expression : "concat = s1 + s2 + s3;"
/*		-> Problem : Above expression is equal to "concat = s1.operator+(s2).operator+(s3);"
/*			-> Memory allocations are executed twice. -> Ineffeciency!!!
/*		-> Solution : Use variadic template to execute memory allocation at once!
*/

size_t get_string_size(const char* s);
size_t get_string_size(const std::string s);
template <typename String, typename... Strings>
size_t get_string_size(const String& s, Strings... strs);

void append_string(std::string* concat_str);		// Final execution for the recursive structure.
template <typename String, typename... Strings>
void append_string(std::string* concat_str, const String& s, Strings... strs);

//template <typename String>
//std::string str_concat(const String& s) {
//	return std::string(s);
//}

template <typename String, typename... Strings>
std::string str_concat(const String& s, Strings... strs);

void variadic_template_str_concat_test();




// Concept) sizeof operator of parameter pack : returns the size of the pack.
// Application) average_calculation_function
int sum_all_variadic();
template <typename... Ints>
int sum_all_variadic(int num, Ints... nums);

template <typename... Ints>
double calculate_average_variadic(Ints... nums);

void variadic_template_size_of_test();



// Concept) Fold Expression
//  - Goal : Simplify the recursive expression of the variadic template.
template <typename... Ints>
int sum_all_fold_exp(Ints... nums);

void fold_expression_test();
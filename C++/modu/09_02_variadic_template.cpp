#include "09_02_variadic_template.h"


void variadic_template_print_test() {
	variadic_template_print(1);
	variadic_template_print("a");
	variadic_template_print(1, "a", 1.2);
}


size_t get_string_size(const char* s) { return strlen(s); }
size_t get_string_size(const std::string s) { return s.size(); }

template <typename String, typename... Strings>
size_t get_string_size(const String& s, Strings... strs) { return get_string_size(s) + get_string_size(strs...); }

void append_string(std::string* concat_str) { return; }		// Final execution for the recursive structure.
template <typename String, typename... Strings>
void append_string(std::string* concat_str, const String& s, Strings... strs) {
	concat_str->append(s);
	append_string(concat_str, strs...);
}


template <typename String, typename... Strings>
std::string str_concat(const String& s, Strings... strs) {

	size_t total_str_size = get_string_size(s, strs...);

	std::string result;
	result.reserve(total_str_size);
	result = s;

	append_string(&result, strs...);

	return result;
}


void variadic_template_str_concat_test() {
	std::cout << str_concat(std::string("abc"), "123412341234", std::string("AAAAAAA"));
}


int sum_all_variadic() { return 0; }
template <typename... Ints>
int sum_all_variadic(int num, Ints... nums) { return num + sum_all_variadic(nums...); }

template <typename... Ints>
double calculate_average_variadic(Ints... nums) {
	return static_cast<double>(sum_all_variadic(nums...)) / sizeof...(nums);		// sizeof... keyword!
}

void variadic_template_size_of_test() {
	std::cout << calculate_average_variadic(1, 3, 11, 18) << std::endl;
}

template <typename... Ints>
int sum_all_fold_exp(Ints... nums) {
	return (... + nums);	// <- Fold Expression
}

void fold_expression_test() {
	std::cout << sum_all_fold_exp(1, 2, 3) << std::endl;
}
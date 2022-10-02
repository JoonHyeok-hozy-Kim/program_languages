#pragma once
#include "00_main.h"

int main() {

	/* 1-1. Hello World */
	//say_hello();			 // Test printing "Hello World" in C++.

	/* 1-2. Namespace*/
	//call_namespaces();	 // Test various ways of defining and calling namespaces.

	/* 1-3 Similarities with C */
	//variables();		// Test defining and calling various data types as variables.
	//pointers();		// Test pointing and shifting various variables using pointers.
	//user_input();		// Test user input and output functions (iostream library)


	/* 2. Reference */
	//c_pointer_review();				// Brief review on pointer related syntaxes in C
	//reference_usage();				// Define and try various operations with a reference to a variable
	//reference_vs_pointer();			// Pointer vs Reference
	//reference_array_test();			// References to array elements

	/* Reference and Function */
	//reference_as_input_parameter();	// Using reference as a function input parameter
	//reference_as_output_test();		// Reference output only allowed when the function input is a reference. In order to prevent dangling reference.


	/* 3. Introduction to the Objective Oriented Programming in C++ */
	//new_delete_test();		// syntax for new and delete
	//array_allocation_with_new();	// 

	/* 4. Objective Oriented Programming */
	/* 4-1. Class */
	//animal_class_test();
	//date_class_test();

	/* 4-2. Function Overload */
	//overload_variables_test();
	//implicit_type_change_test();
	//date_test();

	/* 4-3. Copy Constructor and Destructor */
	//destructor_test();		// Constructor and Destructor Test
	//copy_constructor_test();	// Copy Constructor Test

	/* 4-4. Constant and Static */
	//initializer_list_and_const_test();
	//this_test();
	//ref_return_test();
	//const_function_test();

	/* 4-5. [Application] Custom String Class implementation : MyString */
	//mystring_instance_test();

	/* 4-6. Explicit and Mutable */
	//explict_test();
	//mutable_test();


	/* 5-1. Operator Overloading */
	//equality_operator_test();
	//arithmetic_and_assignment_operator_overloading_test();
	//complex_string_constructor_test();

	/* 5-2. Operator Overloading Advanced */
	//friend_class_and_function_test();
	//binary_operator_overloading_test();
	//iostream_operator_overloading_test();
	//subscript_operator_overloading_test();
	//wrapper_int_class_test();
	//increment_operators_overloading_test();

	/* 5-3. Application : N-Dimensional-Array Implementation */
	//array_construction_test();

	/* 6-1. Inheritance */
	//string_class_test();
	//inheritance_test();

	/* 6-2 */
	//up_casting_test();
	//down_casting_test();
	//dynamic_binding_test();

	/* 6-3 */
	//virtual_destructor_test();
	//referece_input_virtual_function_test();
	//abstract_class_instanciation_test();
	//multiple_inheritance_test();
	//diamond_inheritance_test();

	/* 7-1 */
	//istream_string_instance_test();
	//wrong_initial_input_error_test();
	//solution_input_error_test();
	//hexadecimal_input_test_with_format_flag();
	//hexadecimal_input_test_with_manipulator();
	//stream_buffer_class_manipulation();

	/* 7-2 */
	/* Reading Tests */
	//ifstream_read_test();
	//ifstream_close_test();
	//ifstream_binary_reading_test();
	//ifstream_read_whole_test();
	//ifstream_read_by_line_test();
	//string_read_by_line_test();
	/* Writing Tests */
	//ostream_write_test();
	//ostream_append_test();
	//ofstream_operator_overloading_test();
	/* String Stream Test */
	//istringstream_test();
	//istringstream_str_to_double_test();
	//istringstream_int_to_str_test();


	/* 8-1 */
	//vector_test();
	//stack_test();
	//num_stack_test();
	//txttable_test();

	/* 8-2 */
	//time_t_test();
	//substr_test();

	/* 9-1 */
	//template_vector_test();
	//bool_vector_test();
	//function_template_max_test();
	//swap_function_test();
	//bubble_sort_test();
	//bubble_sort_reverse_test();
	//non_type_template_argument_test();
	//non_type_template_argument_default_test();
	//non_type_template_argument_array_test();
	//print_array_test();
	//test_space_test();

	/* 9-2 */
	//variadic_template_print_test();
	//variadic_template_str_concat_test();
	//variadic_template_size_of_test();
	//fold_expression_test();

	/* 9-3 */
	//custom_array_test();
	//custom_int_test();
	//custom_factorial_test();
	//gcd_test();
	//tmp_gcd_test();
	//tmp_ratio_test();
	//tmp_using_test();
	//tmp_fibo_test();

	/* 9-4 */
	//tmp_is_prime_test();
	//tmp_new_ratio_test();
	//temp_unit_test();

	/* 10-1 */
	//stl_vector_test();
	//range_based_for_loop_test();
	//stl_list_test();
	//stl_deque_test();

	/* 10-2 */
	//stl_set_test();
	//stl_set_custom_object_insertion_test();
	//stl_map_insertion_test();
	//stl_map_search_test();
	//stl_multset_multimap_test();
	//unordered_set_unordered_map_test();
	//custom_hash_test();

	/* 10-3 */
	//vector_sort_test();
	//vector_reverse_sort_test();
	//partial_sort_test();
	//stable_sort_test();
	//stl_remove_test();
	//stl_custom_remove_test();
	//stl_custom_lambda_remove_odd_number_test();
	//stl_custom_lambda_remove_first_two_num_less_than_5();
	//stl_transform_add_one_test();
	//stl_find_function_test();
	//stl_find_if_function_test();

	/* 10-4 */
	//stl_string_trait_compare_test();
	//stl_string_sso_check_test();
	//stl_string_literal_operator_test();
	//stl_string_raw_string_literal_test();
	//stl_string_raw_string_literal_exception();
	//stl_string_utf_32_test();
	//stl_string_utf_8_test();
	//stl_string_utf_8_parsing_test();
	//stl_string_utf_16_test();
	//stl_string_utf_16_korean_jaum_test();
	//stl_string_string_view_redundant_memory_test();
	//stl_string_string_view_find_test();
	//stl_string_string_view_substr_test();

	/* 11 */
	//exception_simple_exception_test();
	//exception_stack_unwinding_test();
	//exception_throw_various_test();
	//exception_inheritance_test();
	//exception_catch_every_thing_test();
	//exception_noexcept_test();

	/* 12 */
	//rvalue_copy_elision_test();
	//rvalue_reference_test();
	//rvalue_moving_constructor_test();
	//rvalue_moving_constructor_noexcept_container_test();
	//move_semantics_copy_swap_test();
	//move_semantics_simple_test();
	//move_semantics_MyString_test();
	//move_semantics_class_in_class_test();
	//perfect_forwarding_wrapper_function_test();
	perfect_forwarding_wrapper_universal_ref_test();

	return 0;
}

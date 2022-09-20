* Back to [Program Languages Main](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/README.md)

### 1-1. [Introduction : Printing "Hello World" in C++](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/01_01_hello_world_cpp.cpp)
### 1-2. [Namespace](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/01_02_namespace.cpp)
### 1-3. [Similarities with C](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/01_03_similarities_with_c.cpp)
---
### 2. [Reference](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/02_reference.cpp)
* reference operator : &
---
### 3. [Introduction to the Objective Oriented Programming(OOP) in C++](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/03_objective_oriented_programming_intro.cpp)
---
### 4-1. [[OOP] Class](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/04_01_oop_class.cpp)
### 4-2. [[OOP] Function Overload](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/04_02_function_overload.cpp)
### 4-3. [[OOP] Copy Constructor and Destructor](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/04_03_copy_costruuctor_and_destructor.cpp)
* private and public
* copy constructor
* destructor
### 4-4. [[OOP] Constant and Static](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/04_04_const_and_static.cpp)
* initializer list
* const variable in Class
* static variable
* "this" keyword
* reference returning function
* const function : AKA read-only function
### 4-5. [[OOP] Application : Custom String Class Implementaion](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/04_05_custom_string_class.h)
### 4-6. [[OOP] Explicit and Mutable](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/04_06_explicit_and_mutable.cpp)
* explicit vs implicit
* mutable
---
### 5-1. [Operator Overloading](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/05_01_operator_overloading.cpp)
* comparison operator : ==
* arithmetic operator : +, -, *, /
* assignment operator : =, +=, -=, *=, /=
* Application : Complex class
### 5-2. [Operator Overloading Advanced](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/05_02_operator_overloading_advanced.cpp)
* "friend" keyword : friend class, friend function
* binary operator
* input/output operator
* subscript operator : []
* Wrapper Class
* pre/post-increment/decrement operator : ++, --
### 5-3. [Operator Overloading Application : N-Dimensional Array Implementation](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/05_03_application_n_dimensional_array.cpp)
* casting
  * static_cast : (syntax) static_cast<int>(float_variable);
  * const_cast
  * dynamic_cast
  * reinterpret_cast
---
### 6-1. [Inheritance](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/06_01_inheritance.cpp)
* C++'s 'string' class
* inheritance
* method overriding
* keyword : "public" / "protected" / "private"
### 6-2. [Virtual Function and Polymorphism](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/06_02_virtual_function_and_polymorphism.cpp)
* up-casting
* down-casting
* dynamic-casting
* dynamic binding : [keyword] "virtual", "override"
* polymorphism
### 6-2. [More Topics for Virtual Function and Polymorphism](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/06_03_virtual_function_and_polymorphism_advanced.cpp)
* virtual destructor
* virtual function table
* pure virtual function
  * abstract class
* multiple inheritance
  * diamond inheritance
---
### 7-1. [Input and Output in C++](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/07_01_io.cpp)
* io related classes in C++ [(See image)](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/images/07_01_01_io_classes_in_cpp.png)
* istream
	* status flags of streams
		1. goodbit : io available
		2. badbit : recovery unavailable
		3. failbit : recovery available
		4. eofbit : reached end of file
* format flag
	* Used for std::cin.setf() function
	* ex.) std::ios_base::hex
* manipulator
	* ex)
		* std::endl
		* std::hex
* stream buffer
	* streambuf class
### 7-2. [Stream Applications](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/07_02_io_streams.cpp)
* file stream
	* ifstream
	* ofstream
		* options
			* std::ios::app : Append the new contents. Previous contents secured.
			* std::ios::ate : Position at the end but can move forward, i.e., contents can be altered.
			* std::ios::trunc : Truncate the file.
		* operator overloading
			* <<
* sstream
	* std::istringstream
	* std::ostringstream
		* string formatting 
---
### 8-1. [Application : Excel Implementation](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/08_01_application_custom_excel_program.cpp)
* [time related data types](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/08_02_excel_advanced.cpp)
	* tm
	* time_t
	* mktime()
---
### 9-1. [Templates](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/09_01_templates.h)
* template
* class template instantiation
* template specialization
* function template
* function object (a.k.a. functor)
* non-type template arguments
### 9-2. [Variadic Templates](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/09_02_variadic_template.h)
* variadic template
* parameter pack
* fold expression
### 9-3. [Template Meta Programming](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/09_03_template_meta_programming.h)
* meta programming : programming with the compile time codes
### 9-4. [TMP advanced](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/09_04_tmp_advanced.h)
* dependent type
* unit library
* "auto" keyword
---
### 10-1. [Standard Template Library (STL)](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/10_01_stl_vector_list_deque.cpp)
* C++ standard template library overview
  1. container : vector, list, deque
  2. iterator
  3. algorithm
* sequence container
* iterator
* range-based for loop
### 10-2. [Associative Containers](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/10_02_stl_associative_containers.cpp)
* associative containers
  * set, map, multiset, multimap
  * unordered set, unordered map
### 10-3. [STL Algorithms](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/10_03_stl_algorithms.cpp)
* sort algorithms
	* sort
	* partial_sort
	* stable_sort
* remove functions for iterables
	* remove
	* remove_if
* lambda function
* transform function for iterables
* search functions for iterables
	* find
	* find_if
	* any_of
	* all_of
### 10-4. [STL string](https://github.com/JoonHyeok-hozy-Kim/program_languages/blob/main/C%2B%2B/10_04_stl_string.cpp)
* basic_string class
	* customizing traits
* short string optimization (SSO)
* literal operator : operator "" s
* raw string literal
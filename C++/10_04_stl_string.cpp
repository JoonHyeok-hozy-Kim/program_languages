#include "10_04_stl_string.h"


/* std:: string is an instance of basic_string class

	* Definition of basic_string class
	-----------------------------------------------
	template <class CharT, class Traits = std::char_traits<CharT>, class Allocator = std::allocator<CharT> >
	class basic_string;
	-----------------------------------------------

	* Traits define all the operations of string class : std::char_traits
*/


namespace string_test {

	// modifying methods of Traits!
	struct my_char_traits : public std::char_traits<char> {

		static int get_real_rank(char c) {
			if (isdigit(c)) {
				return c + 256;		// modify the ranks of digits -> way behind alphabets.
			}
			return c;
		}

		static bool lt(char c1, char c2) {
			return get_real_rank(c1) < get_real_rank(c2);	// less than operation by new rule!
		}

		static int compare(const char* s1, const char* s2, size_t n) {	// modify compare method with new rule!
			while (n-- != 0) {
				if (get_real_rank(*s1) < get_real_rank(*s2)) {
					return -1;
				}
				if (get_real_rank(*s1) > get_real_rank(*s2)) {
					return 1;
				}
				++s1;
				++s2;
			}
			return 0;
		}

	};

}

void stl_string_trait_compare_test() {
	std::basic_string<char, string_test::my_char_traits> s1 = "1a";
	std::basic_string<char, string_test::my_char_traits> s2 = "a1";

	std::cout << "Custom string : s1<s2= " << (s1 < s2) << std::endl;
	std::cout << "Custom string : s1>s2= " << (s1 > s2) << std::endl;

	std::string ss1 = "1a";
	std::string ss2 = "a1";

	std::cout << "Custom string : ss1<ss2= " << (ss1 < ss2) << std::endl;
	std::cout << "Custom string : ss1>ss2= " << (ss1 > ss2) << std::endl;
}




/////////////////////////////////////////////////////////////////////
/* Short String Optimization (SSO) : For short strings, basic_string save them in the object rather than allocating memories.
*/
void* operator new(std::size_t count) {
	std::cout << count << " bytes allocated. " << std::endl;	// Debug text added for checking the memory allocation!
	return malloc(count);
}

void stl_string_sso_check_test() {
	std::cout << "s1 created." << std::endl;
	std::string s1 = "Very loooooooooooooooooooooooong string.";
	std::cout << "The size of s1 : " << sizeof(s1) << std::endl;

	std::cout << "s2 created." << std::endl;
	std::string s2 = "s";
	std::cout << "The size of s2 : " << sizeof(s2) << std::endl;

}



/////////////////////////////////////////////////////////////////////
/* Literal operator : New way of creating a literal
*/
using namespace std::literals;	// Must use the namespace std::literals !!!
void stl_string_literal_operator_test() {
	auto s1 = "abcd"s;
	std::cout << s1 << "'s size : " << s1.size() << std::endl;
}

void stl_string_raw_string_literal_test() {
	std::string str = R"(anything can go inside here including
/ / / \ \ \
#define #include 
\n\n no escape code required.)";
	std::cout << str << std::endl;
}

void stl_string_raw_string_literal_exception() {
	// only exception is )" characters usage.
	// I you need to put them into a literal, use the syntax : R"_any_delimeter_( _text_comes_here_ )_any_delimeter_"
	std::string str = R"hozy( )";  )hozy";
	std::cout << str << std::endl;
}
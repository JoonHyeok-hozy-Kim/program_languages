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
//void* operator new(std::size_t count) {
//	std::cout << count << " bytes allocated. " << std::endl;	// Debug text added for checking the memory allocation!
//	return malloc(count);
//}

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


/////////////////////////////////////////////////////////////////////
/* Unicode
*/

/* UTF-32 */
void stl_string_utf_32_test() {

	/* In case of UTF-8,
		Every character is in 4-byte length.
	*/
	std::u32string u32_str = U"이건 UTF-32 문자열";		// Syntax U"" : UTF-32 encoding
	std::cout << u32_str.size() << std::endl;
}

/* UTF-8 */
void stl_string_utf_8_test() {

	/* In case of UTF-8,
		1. 0       ~ 0x7F     : 1 byte
		2. 0x80    ~ 0x7FF    : 2 byte
		3. 0x800   ~ 0xFFFF   : 3 byte
		4. 0x10000 ~ 0x10FFFF : 4 byte

		Enghlish alphabets : 0 ~ 127          -> all 1 bytes.
		Korean Characters  : 0xAC00 ~ 0xD7AF  -> all 3 bytes
	*/

	std::string u8_str = u8"이건 UTF-8 문자열";		// Syntax u8"" : UTF-8 encoding
	std::cout << u8_str.size() << std::endl;	
}

void stl_string_utf_8_parsing_test() {
	std::string u8_str = u8"이건 UTF-8 문자열";
	size_t i = 0;
	size_t len = 0;

	while (i < u8_str.size()) {
		int char_size = 0;

		if ((u8_str[i] & 0b11111000) == 0b11110000) {
			char_size = 4;
		}
		else if ((u8_str[i] & 0b11110000) == 0b11100000) {
			char_size = 3;
		}
		else if ((u8_str[i] & 0b11100000) == 0b11000000) {
			char_size = 2;
		}
		else if ((u8_str[i] & 0b10000000) == 0b00000000) {
			char_size = 1;
		}
		else {
			std::cout << "Unexpected character found!" << std::endl;
			char_size = 1;
		}

		std::cout << char_size << " -> " << u8_str.substr(i, char_size) << std::endl;

		i += char_size;
		len++;
	}
	std::cout << "True length of the string : " << len << std::endl;
}


/* UTF-16 */
void stl_string_utf_16_test() {

	/* In case of UTF-16,
		Most characters are in 2-byte length.
	*/

	std::u16string u16_str = u"이건 UTF-16 문자열";		// Syntax u"" : UTF-8 encoding
	std::cout << u16_str.size() << std::endl;
}

void stl_string_utf_16_korean_jaum_test() {
	std::u16string u16_str = u"나는 짱이다";
	std::string jaum[] = { "ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ",
						   "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ",
						   "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" };
	for (char16_t c : u16_str) {
		if (!(0xAC00 <= c && c <= 0xD7A3)){		// lower and upper bound of Korean characters
			continue;
		}
		int offset = c - 0xAC00;
		int jaum_offset = offset / 0x24C;	// Every jaum has 0x24C set of characters. ex) (ㄱ) : 가, 각, 갂, 간, ...
		std::cout << jaum[jaum_offset];
	}
}


///////////////////////////////////////////////////////////
/* Concept) string_view

	- Consider the case that we only READ a string.
		- We may use "const std::string& str" as a input parameter.
			-> However, it creates unnecessary object -> wasting memory!

*/

//void* operator new(std::size_t count) {
//	std::cout << count << " bytes allocated. " << std::endl;	// Debug text added for checking the memory allocation!
//	return malloc(count);
//}

bool stl_string_contains_very(const std::string& str) {
	return str.find("very") != std::string::npos;
}

void stl_string_string_view_redundant_memory_test() {
	std::cout << std::boolalpha << stl_string_contains_very("C++ is very hard")
		<< std::endl;

	std::cout << std::boolalpha << stl_string_contains_very("C++ is not easy at all")
		<< std::endl;
}

bool stl_string_view_contains_very(std::string_view str) {
	return str.find("very") != std::string_view::npos;
}

void stl_string_string_view_find_test() {
	std::cout << std::boolalpha << stl_string_view_contains_very("C++ is very hard")
		<< std::endl;

	std::cout << std::boolalpha << stl_string_view_contains_very("C++ is not easy at all")
		<< std::endl;
}

void stl_string_string_view_substr_test() {
	std::string s = "C++ is not easy at all";
	std::cout << s.substr(0, 5) << std::endl << std::endl;

	std::string_view sv = "C++ is not easy at all";
	std::cout << sv.substr(0, 5) << std::endl << std::endl;
}
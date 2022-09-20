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

		static int compare(const char* s1, const char* s2, size_t n) {
			sl
		}

	};


}
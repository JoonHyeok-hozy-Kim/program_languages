#include "07_01_io.h"
#include <iostream>
#include <string>

// Recall that >> operator is defined in istream class.
// Although data types that can be used for std::cout >> syntax is limited to the ones already defined, we can expanse the usage by overriding the operator usage.

// ex.) getting std::string instance for istream's >> operator
//std::istream& operator>>(std::istream& in, std::string& s);

void istream_string_instance_test() {

	std::string s;

	// Test
	std::cin >> s;
	std::cout << "Input : " << s << std::endl;
}


// Prop.) std::cin ignores empty spaces or line change


// Tech.) How to deal with not defined data type input
// ex.) Situation : only int input allowed but char input given.

void initial_input_error_test() {
	int t;
	while (true) {
		std::cin >> t;
		std::cout << "Input value : " << t << std::endl;
		if (t == 0) break;
	}
}


void solution_input_error_test() {
	int t;
	while (true) {
		std::cin >> t;
		std::cout << "Input : " << t << std::endl;
		if (std::cin.fail()) {		// true when failbit is true!
			std::cout << "Wrong format. Please input integer." << std::endl;
			std::cin.clear();		// initialize flags!
			std::cin.ignore(100, '\n');		// ignore until \n shows up!
		}
		if (t == 1) break;
	}
}
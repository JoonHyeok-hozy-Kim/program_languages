#include "07_01_io.h"
#include <iostream>
#include <string>

// Recall that >> operator is defined in istream class.
// Although the data types that can be used for "std::cout >> syntax" is limited to the ones already defined in istream class, 
// we can expanse the usage by overriding the operator usage.

// ex.) getting std::string instance for istream's >> operator
//std::istream& operator>>(std::istream& in, std::string& s) { /* TBD */ };

void istream_string_instance_test() {

	std::string s;

	// Test
	std::cin >> s;
	std::cout << "Input : " << s << std::endl;
}


// Prop.) std::cin ignores empty spaces or line change


// Tech.) How to deal with not defined data type input
// ex.) Situation : only int input allowed but char input given.

void wrong_initial_input_error_test() {
	int t;
	while (true) {
		std::cin >> t;
		std::cout << "Input value : " << t << std::endl;
		if (t == -1) break;
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
		if (t == -1) break;
	}
}


//////////////////////////////////////////////////////////////////
// We can define the format of the input.
// ex 1.) hexadecimal input using std::cin.setf() function and format flag
void hexadecimal_input_test_with_format_flag() {
	int t;
	while (true) {
		std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
		std::cin >> t;
		std::cout << "Input : " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "[ERROR] Wrong Format." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if (t == -1) return;
	}
}


// ex 2.) hexadecimal input using manipulator
void hexadecimal_input_test_with_manipulator() {
	int t;
	while (true) {
		std::cin >> std::hex >> t;
		std::cout << "Input : " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "[ERROR] Wrong Format." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if (t == -1) return;
	}
}


///////////////////////////////////////////////////
// Stream Buffer Class manipulation
void stream_buffer_class_manipulation() {
	std::string s;
	std::cin >> s;

	char peek = std::cin.rdbuf()->snextc();
	/* 
	1) rdbuf() returns the pointer of the stream object
	2) snextc() peeks at the next word, not reading!
	*/


	if (std::cin.fail()) std::cout << "Failed!" << std::endl;
	std::cout << "The first letter of the second word : " << peek << std::endl;
	std::cout << s;
}
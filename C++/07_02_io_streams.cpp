#include "07_02_io_streams.h"
#include <fstream>
#include <iostream>
#include <string>

void ifstream_read_test() {

	std::ifstream in("07_02_read_test.txt");
	std::string s;

	if (in.is_open()) {
		in >> s;
		std::cout << "Input text : " << s << std::endl;
	}
	else {
		std::cout << "File not found." << std::endl;
	}
	return;
}



// Tech.) close() is not always required in C++. (Recall that fclose was mandatory in C)
//		  However, when multiple files are being read, previous ones should be closed as follows.
void ifstream_close_test() {
	std::ifstream in("07_02_read_test.txt");
	std::string s;

	if (in.is_open()) {
		in >> s;
		std::cout << "First word : " << s << std::endl;
	}
	else {
		std::cout << "File not found." << std::endl;
	}

	in.close();	// Close current file.

	in.open("07_02_read_test2.txt");	// Open new file.
	if (in.is_open()) {
		in >> s;
		std::cout << "First word : " << s << std::endl;
	}
	else {
		std::cout << "File not found." << std::endl;
	}
}


// Tech.) Reading files in binary
void ifstream_binary_reading_test() {
	std::ifstream in("07_02_read_test.txt", std::ios::binary); // binary parameter

	// Reading 4 bytes using integer x => NOT used frequently.
	int x;
	if (in.is_open()) {
		in.read((char*)(&x), 4);	// Read 4 bytes!
		std::cout << std::hex << x << std::endl;
	}
	else {
		std::cout << "File not found." << std::endl;
	}
	in.close();


	std::ifstream in2("07_02_read_test.txt", std::ios::binary); // binary parameter
	// Reading the number of characters using array.
	char y[4];
	if (in2.is_open()) {
		in2.read(y, 4);
		std::cout << std::hex << y << std::endl;
	}
	else {
		std::cout << "File not found." << std::endl;
	}

	return;
}
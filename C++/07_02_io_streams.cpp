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


// Tech.) Reading the whole file using positions.
// seekg() and tellg() function.
void ifstream_read_whole_test() {
	//std::ifstream in("07_02_read_test.txt");
	std::ifstream in("07_02_two_para_text.txt");
	std::string s;

	if (in.is_open()) {
		in.seekg(0, std::ios::end);		// move positioner to the end.

		int size = in.tellg();			// read the position : the size of the file.
		s.resize(size);					// resize string variable s into the size above. (in byte!)

		in.seekg(0, std::ios::beg);		// move positioner to the front again.

		in.read(&s[0], size);			// read the whole file!

		std::cout << s << std::endl;
	}
	else {
		std::cout << "File not found" << std::endl;
	}
	return;
}


// Tech.) Ready by lines using getline() function of ifstream class --> Not suggested!! Buffer size should be given.
void ifstream_read_by_line_test() {
	//std::ifstream in("07_02_read_test.txt");
	std::ifstream in("07_02_two_para_text.txt");

	char buf[10000];

	if (!in.is_open()) {
		std::cout << "File not found!" << std::endl;
		return;
	}

	while (in) {
		//in.getline(buf, 10000);			// gets 10000-1 chars. why?). A space required for the \n.
		in.getline(buf, 1000, '.');		// '.' as the delimiter.
		std::cout << buf << std::endl;
	}
	return;
}


// Tech.) Read by lines using getline() function of string class
void string_read_by_line_test() {
	//std::ifstream in("07_02_read_test.txt");
	std::ifstream in("07_02_two_para_text.txt");

	if (!in.is_open()) {
		std::cout << "File not found." << std::endl;
		return;
	}

	std::string s;
	while (in) {
		getline(in, s, '.');		// getline() function defined in string class (not ifstream)
		std::cout << s << std::endl;
	}
	return;
}


///////////////////////////////////////////////////////////
// Tech.) How to write on files.
void ostream_write_test() {
	std::ofstream out("07_02_write_test1.txt");
	std::string s;
	if (out.is_open()) {
		out << "Test writing text.";
		std::cout << "Successfully written." << std::endl;
	}
	else {
		std::cout << "File not found" << std::endl;
	}
	return;
}

// Tech.) How to append text to the existing file
void ostream_append_test() {
	std::ofstream out("07_02_write_test1.txt", std::ios::app);	// Appending option.
	std::string s;
	if (out.is_open()) {
		out << " Appending text.";
		std::cout << "Successfully appended." << std::endl;
	}
	else {
		std::cout << "File not found" << std::endl;
	}
	return;
}


////////////////////////////////////////////////////
// Tech.) << operator overloading
class Human {
	std::string name;
	int age;

public:
	Human(const std::string& name, int age) : name(name), age(age) {}
	std::string get_info() { return "Name : " + name + " / Age : " + std::to_string(age); }

	friend std::ofstream& operator<<(std::ofstream& o, Human h);
};

std::ofstream& operator<<(std::ofstream& o, Human h) {
	o << h.get_info();
	return o;
}

void ofstream_operator_overloading_test() {
	std::ofstream out("07_02_write_test1.txt", std::ios::app);
	out << "\n";
	Human h1("Joon", 28);
	out << h1 << std::endl;
	return;
}


//////////////////////////////////////////////////////
// string stream : regarding a string as a stream
#include <sstream>
void istringstream_test() {
	std::istringstream iss("123");
	int x;
	iss >> x;
	std::cout << "Input Data : " << x << std::endl;
	return;
}

// Application : format change function using string stream
double to_number(std::string s) {
	std::istringstream iss(s);
	double n;
	iss >> n;
	return n;
}

void istringstream_str_to_double_test() {
	std::string s1 = "10.9";
	std::string s2 = "12.3";
	std::cout << s1 << " x " << s2 << " = " << to_number(s1) * to_number(s2) << std::endl;
}

std::string to_str(int x) {
	std::ostringstream oss;
	oss << x;
	return oss.str();
}

void istringstream_int_to_str_test() {
	int x = 10;
	int y = 5;
	std::cout << to_str(x) << " x " << to_str(y) << " = " << to_str(x*y) << std::endl;
}

#include "04_05_custom_string_class.h"
#include <stdlib.h>
#include <iostream>

class HozyString {

	int length;
	char* data;

public:
	HozyString();
	HozyString(char c);
	HozyString(char* cp);
	int len();
	void print();
	HozyString& concat(HozyString s);
	int contain(HozyString s);
	bool compare(HozyString s);
	bool lexicographically_gt(HozyString s);

};

HozyString::HozyString() {
	length = 0;
	data = (char*)(malloc(sizeof(char) * (length + 1)));
	data[length] = '\0';
}

HozyString::HozyString(char c) {
	length = 1;
	data = (char*)(malloc(sizeof(char) * (length + 1)));
	data[0] = c;
	data[length] = '\0';
}

HozyString::HozyString(char* cp) {
	length = 0;
	while (*cp) {
		length++;
		cp++;
	}
	data = (char*)(malloc(sizeof(char) * (length + 1)));
	data[length] = '\0';
	for (int i = 0; i < length; i++) {
		cp--;
		data[length - 1 - i] = *cp;
	}
}

int HozyString::len() {
	return length;
}

void HozyString::print() {
	if (length > 0) {
		for (int i = 0; i < length; i++) {
			std::cout << data[i];
		}
	}
	std::cout << data[length] << std::endl;
}

HozyString& HozyString::concat(HozyString s) {
	char* new_data;
	new_data = (char*)(malloc(sizeof(char) * (length + s.length + 1)));
	for (int i = 0; i < length; i++) {
		new_data[i] = data[i];
	}
	for (int i = 0; i < s.length; i++) {
		new_data[length + i] = s.data[i];
	}
	length += s.length;
	new_data[length] = '\0';
	data = new_data;
	return *this;
}

int HozyString::contain(HozyString s) {
	// Implemented in Brute Force Method
	int correct_cnt;
	for (int i = 0; i < length - s.length + 1; i++) {
		correct_cnt = 0;
		for (int j = 0; j < s.length; j++) {
			if (data[i + j] == s.data[j]) correct_cnt++;
			else break;
		}
		if (correct_cnt == s.length) return i;
	}
	return -1;
}

bool HozyString::compare(HozyString s) {
	if (length != s.length) return false;
	for (int i = 0; i < length; i++) {
		if (data[i] != s.data[i]) return false;
	}
	return true;
}

bool HozyString::lexicographically_gt(HozyString s) {
	int l;
	if (length < s.length) l = length;
	else l = s.length;

	for (int j = 0; j < l; j++) {
		if (data[j] > s.data[j]) return true;
		else if (data[j] < s.data[j]) return false;
	}

	if (length > s.length) return true;
	else return false;
}



void instance_test() {
	HozyString h1;
	h1.print();

	HozyString h2('c');
	h2.print();

	HozyString h3('d');
	h3.print();

	char ccc[5] = { 'a', 'b', 'c', 'd', '\0' };
	HozyString h4(ccc);
	h4.print();

	HozyString h5 = h1.concat(h2);
	h1.print();
	h5.print();

	HozyString h6 = h2.concat(h3);
	h6.print();

	HozyString h7 = h3.concat(h4);
	h7.print();

	HozyString h8 = h4.concat(h7);
	h8.print();

	std::cout << "Contain Test" << std::endl;
	char t9[6];
	char t10[4];
	strcpy(t9, "abcde");
	strcpy(t10, "cdz");
	HozyString h9(t9);
	HozyString h10(t10);
	h9.print();
	h10.print();
	std::cout << h9.contain(h10) << std::endl;
	char t11[4];
	strcpy(t11, "de");
	HozyString h11(t11);
	h11.print();
	std::cout << h9.contain(h11) << std::endl;


	std::cout << "Compare Test" << std::endl;
	std::cout << h10.compare(h11) << std::endl;
	char t12[4];
	strcpy(t12, "cdz");
	HozyString h12(t12);
	std::cout << h10.compare(h12) << std::endl;


	std::cout << "Lexi Test" << std::endl;
	HozyString l1('a');
	HozyString l2('a');
	std::cout << l1.lexicographically_gt(l2) << std::endl;
	HozyString l3('b');
	std::cout << l1.lexicographically_gt(l3) << std::endl;
	char c4[3] = { 'a', 'b', '\0' };
	HozyString l4(c4);
	std::cout << l1.lexicographically_gt(l4) << std::endl;
	std::cout << l3.lexicographically_gt(l4) << std::endl;
	char c5[3] = { 'a', 'c', '\0' };
	HozyString l5(c5);
	std::cout << l5.lexicographically_gt(l4) << std::endl;
}
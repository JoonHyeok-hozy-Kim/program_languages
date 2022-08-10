#include "04_05_custom_string_class.h"
#include <stdlib.h>
#include <iostream>

MyString::MyString(char c){
	string_length = 1;
	capacity = 1;
	string_content = new char[1];
	string_content[0] = c;
}

MyString::MyString(const char* str) {
	string_length = (int)strlen(str);
	capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i < string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i < string_length; i++) string_content[i] = str.string_content[i];
}

void MyString::print() const {
	for (int i = 0; i < string_length; i++) {
		std::cout << string_content[i];
	}
}

void MyString::println() const {
	this->print();
	std::cout << std::endl;
}

void MyString::capacity_change(int new_capacity, int prev_capacity) {
	//std::cout << "In capacity_change("<< new_capacity<< ")" << std::endl;
	char* prev_content = string_content;
	int min_capacity = new_capacity;
	if (min_capacity > prev_capacity) min_capacity = prev_capacity;
	string_content = new char[new_capacity];
	for (int i = 0; i < min_capacity; i++) {
		string_content[i] = prev_content[i];
	}
	capacity = new_capacity;
	delete[] prev_content;
}

void MyString::capacity_check(int target_capacity) {
	int new_capacity = capacity;
	if (capacity < target_capacity) {
		while (new_capacity < target_capacity) new_capacity *= 2;
		this->capacity_change(new_capacity, capacity);
		return;
	}
	else if (capacity > target_capacity * 2) {
		//std::cout << "Point2 : target : " << target_capacity << ", current : " << capacity << std::endl;
		while (new_capacity > target_capacity * 2) new_capacity /= 2;
		this->capacity_change(new_capacity, capacity);
		return;
	}
	return;
}

MyString& MyString::assign(const MyString& str) {
	int str_len = str.length();
	//if (capacity < str_len) this->capacity_change(str_len);
	this->capacity_check(str_len);
	string_length = str_len;
	for (int i = 0; i < str_len; i++) {
		string_content[i] = str.string_content[i];
	}
	return *this;
}

MyString& MyString::assign(const char* str) {
	MyString temp(str);
	return assign(temp);
}

char MyString::at(int i) const {
	if (i > string_length) return NULL;
	else return string_content[i];
}

MyString& MyString::insert(int loc, MyString& str) {
	this->capacity_check(string_length + str.string_length);

	for (int i = string_length; i > loc ; i--) {
		string_content[str.string_length + i - 1] = string_content[i - 1];
	}
	for (int i = 0; i < str.string_length; i++) {
		string_content[loc + i] = str.string_content[i];
	}
	string_length += str.length();
	return *this;
}

MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	this->insert(loc, temp);
	return *this;
}

MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	this->insert(loc, temp);
	return *this;
}

MyString& MyString::erase(int loc, int num) {
	if (loc < string_length || loc + num < string_length) {
		for (int i = loc + num; i < string_length; i++) {
			string_content[i - num] = string_content[i];
		}
		string_length -= num;
		this->capacity_check(string_length);
	}
	else {
		std::cout << "Cannot erase [" << loc << ":" << loc + num << "]." << std::endl;
		return *this;
	}
}

int MyString::find(int start, const MyString& str) const {

	//std::cout << "Brute Force : " << find_brute_force(start, str) << std::endl;
	//std::cout << "KMP : " << find_kmp(start, str) << std::endl;

	//return find_brute_force(start, str);
	return find_kmp(start, str);
}

int MyString::find(int start, const char* str) const {
	MyString temp(str);
	return find(start, temp);
}

int MyString::find(int start, char c) const {
	MyString temp(c);
	return find(start, temp);
}


int MyString::find_brute_force(int start, const MyString& str) const {
	while (start + str.string_length - 1 < string_length) {
		int cnt = 0;
		for (; cnt < str.string_length; cnt++) {
			if (string_content[start + cnt] != str.string_content[cnt]) break;
		}
		if (cnt == str.string_length) return start;
		else start++;
	}
	return -1;
}

int MyString::find_kmp(int start, const MyString& str) const {
	int m = str.string_length;
	if (m == 0) return -1;
	int* fail = _compute_kmp_fail(str);
	int k = 0;
	
	while (start < string_length) {
		if (string_content[start] == str.string_content[k]) {
			if (k == m - 1) return start - m + 1;
			start++;
			k++;
		}
		else if (k > 0) k = fail[k - 1];
		else start++;
	}
	return -1;
}


int* MyString::_compute_kmp_fail(const MyString& str) const {
	int m = str.length();
	int* fail = new int[m];
	for (int i = 0; i < m; i++) fail[i] = 0;
	int j = 1;
	int k = 0;

	while (j < m) {
		if (str.at(j) == str.at(k)) {
			fail[j] = k + 1;
			j++;
			k++;
		}
		else if (k > 0) k = fail[k - 1];
		else j++;
	}
	return fail;
}

int MyString::compare(const MyString& str) const {
	/* 
	Input : MyString instance
	Return : 1 if this is lexicographically greater than, 0 if equal to, and -1 if lesser than input instance.
	*/
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i]) return 1;
		else if (string_content[i] < str.string_content[i]) return -1;
	}
	if (string_length > str.string_length) return 1;
	else if (string_length < str.string_length) return -1;
	else return 0;
}



void mystring_instance_test() {

	MyString* ms_list[3];
	ms_list[0] = new MyString('c');
	ms_list[1] = new MyString("abc");
	ms_list[2] = new MyString(*ms_list[1]);
	
	for (int i = 0; i < 3; i++) {
		std::cout << ms_list[i]->length() << std::endl;
		//ms_list[i]->print();
		ms_list[i]->println();
	}

	ms_list[0]->assign("abcdefg");
	ms_list[0]->println();

	ms_list[1]->assign("bb");
	ms_list[1]->println();
	
	ms_list[2]->assign(*ms_list[0]);
	ms_list[2]->println();

	std::cout << ms_list[2]->at(3) << std::endl;
	std::cout << ms_list[2]->at(0) << std::endl;

	
	ms_list[2]->insert(4, *ms_list[1]);
	ms_list[2]->println();

	ms_list[2]->insert(2, "xxx");
	ms_list[2]->println();

	ms_list[2]->insert(2, 'z');
	ms_list[2]->println();
	
	ms_list[2]->erase(5, 3);
	ms_list[2]->println();

	std::cout << ms_list[2]->find(4, "efg") << std::endl;

	ms_list[0]->assign("aaa");
	ms_list[1]->assign("aab");
	ms_list[2]->assign("aa");
	std::cout << ms_list[0]->compare(*ms_list[1]) << std::endl;
	std::cout << ms_list[0]->compare(*ms_list[2]) << std::endl;

	for (int i = 0; i < 3; i++) {
		delete ms_list[i];
	}
}
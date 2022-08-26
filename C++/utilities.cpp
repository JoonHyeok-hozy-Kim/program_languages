#include "utilities.h"
#include <iostream>

Vector::Vector(int n) : data(new std::string[n]), capacity(n), length(0) {};

std::string Vector::str() {
	std::string s("[");
	for (int i = 0; i < length; i++) {
		s += data[i];
		if (i < length - 1) s += ", ";
	}
	s += "]";
	return s;
}

void Vector::print() {
	std::cout << str() << std::endl;
}

void Vector::capacity_change(double times) {
	std::string* prev_data = data;
	capacity = (int)((double)capacity * times);
	std::cout << "New capa : " << capacity << std::endl;
	if (capacity < length) {
		std::cout << "[Error] In Vector::capacity_change, capacity < length" << std::endl;
		return;
	}
	data = new std::string[capacity];
	for (int i = 0; i < length; i++) data[i] = prev_data[i];
	return;
}

void Vector::push_back(std::string s) {
	if (capacity == length) capacity_change(2);
	data[length] = s;
	length++;
}

std::string Vector::operator[](int i) {
	return data[i];
}

void Vector::remove(int x) {
	if (length <= x) {
		std::cout << "[Error] In Vector::remove, length <= x" << std::endl;
		return;
	}
	if (x < length-1) {
		for (int i = x; i < length-1; i++) {
			data[i] = data[i + 1];
		}
	}
	length--;
	if (length < capacity / 2) capacity_change(.5);
}

int Vector::size() {
	return length;
}


Stack::Stack() : current(NULL), length(0) {}

void Stack::push(std::string s) {
	current = new Node(current, s);
	length++;
}

std::string Stack::pop() {
	if (length < 1) {
		std::cout << "[Error] In Stack::pop, length < 1" << std::endl;
		return NULL;
	}
	Node* popped = current;
	current = current->prev;
	length--;
	return popped->s;
}

std::string Stack::peek() {
	return current->s;
}

bool Stack::is_empty() {
	return (length == 0);
}

int Stack::size() {
	return length;
}

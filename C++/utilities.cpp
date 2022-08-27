#include "utilities.h"

namespace MyExcel {
	/* Vector starts. */
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
		if (x < length - 1) {
			for (int i = x; i < length - 1; i++) {
				data[i] = data[i + 1];
			}
		}
		length--;
		if (length < capacity / 2) capacity_change(.5);
	}

	int Vector::size() {
		return length;
	}
	/* Vector ends. */

	/* Stack starts. */
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
		std::string result = current->s;
		Node* popped = current;
		current = current->prev;
		length--;

		delete popped;
		return result;
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

	Stack::~Stack() {
		while (current) {
			Node* top = current;
			current = current->prev;
			std::cout << "Delete : " << top->s << std::endl;
			delete top;
		}
	}
	/* Stack ends. */

	/* NumStack starts. */
	void NumStack::push(int n) {
		current = new Node(current, n);
		length++;
	}

	int NumStack::pop() {
		Node* top = current;
		int result = top->n;
		current = top->prev;
		length--;
		return result;
	}

	int NumStack::peek() {
		if (length == 0) return NULL;
		return current->n;
	}

	bool NumStack::is_empty() {
		return (length == 0);
	}

	int NumStack::size() {
		return length;
	}

	NumStack::~NumStack() {
		while (current) {
			Node* top = current;
			current = top->prev;
			delete top;
		}
	}
	/* NumStack ends. */



}









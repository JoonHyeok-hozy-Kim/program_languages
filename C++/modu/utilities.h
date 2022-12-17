#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

using std::string;

namespace MyExcel {

	class Vector {
		std::string* data;
		int capacity;
		int length;

	public:
		Vector(int n = 1);
		std::string str();
		void print();
		void capacity_change(double times);
		void push_back(std::string s);
		std::string operator[](int i);
		void remove(int x);
		int size();
		~Vector() { delete[] data; }

	};


	class Stack {

		struct Node {
			Node* prev;
			std::string s;

			Node(Node* prev, std::string s) : prev(prev), s(s) {};
		};

		Node* current;
		int length;

	public:
		Stack();
		void push(std::string s);
		std::string pop();
		std::string peek();
		bool is_empty();
		int size();
		~Stack();

	};

	class NumStack{

		struct Node {
			Node* prev;
			int n;

			Node(Node* prev, int n) : prev(prev), n(n) {};
		};

		Node* current;
		int length;

	public:
		NumStack() : current(NULL), length(0) {}
		void push(int n);
		int pop();
		int peek();
		bool is_empty();
		int size();
		~NumStack();
	};

	class CharStack {

		struct Node {
			Node* prev;
			char c;

			Node(Node* prev, char c) : prev(prev), c(c) {};
		};

		Node* current;
		int length;

	public:
		CharStack() : current(NULL), length(0) {}
		void push(char c);
		int pop();
		int peek();
		bool is_empty();
		int size();
		~CharStack();
	};
}


#endif
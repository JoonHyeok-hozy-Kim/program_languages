#include <string>

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
	~Stack() { delete current; };

};
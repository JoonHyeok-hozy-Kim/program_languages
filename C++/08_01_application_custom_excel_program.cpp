#include <string>
#include <iostream>
#include "utilities.h"

class Table;
class Cell {
	Table* table;		// the table that the cell is contained.
	std::string data;	// the data of the cell in string
	int x, y;			// the coordinate of the cell

public:
	Cell(const std::string& data) : data(data) {
		std::cout << "Cell created. data : " << data << std::endl;
	};
};

class Table {
	Cell*** data_base;			// Two Dimensional array of cells

public:
	Table();
	virtual std::string print_table() = 0;	// Pure virtual function for print_table()
	void reg_cell(Cell* c, int x, int y);	// Register a cell.
	std::string get_cell(int row, int col);		// get data from the specific cell
	~Table() { delete data_base; }
};

std::ostream& operator<<(std::ostream& o, Table& t) {
	o << t.print_table();
	return o;
}

class TextTable : public Table {
public:
	TextTable() : Table() {};
	std::string print_table() override {
		return "abc";
	};
};

class CSVTable : public Table {

};

class HTMLTable : public Table {

};


void cell_creation_test() {
	Cell c1("data1");
}

void vector_test() {
	Vector v;
	//v.print();
	for (int i = 0; i < 17; i++) {
		v.push_back(std::to_string(i));
		//v.print();
	}
	v.print();
	//std::cout << v[3] << std::endl;
	//std::cout << v[15] << std::endl;
	for (int i = 0; i < 17; i++) {
		v.remove(v.size()/2);
		v.print();
	}
}

void stack_test() {
	Stack s;
	for (int i = 0; i < 10; i++) {
		s.push(std::to_string(i));
		std::cout << "Pushed : " << s.peek() << " / Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << "Popped : " << s.pop() << " / Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	}
}
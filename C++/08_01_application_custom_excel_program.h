#include <string>
#include <iostream>
#include <fstream>
#include "utilities.h"

void vector_test();
void stack_test();
void num_stack_test();

class Table;

/* Cell definitions start */
class Cell {
protected:
	int x, y;
	Table* table;
	//std::string data;

public:
	//Cell(std::string data, int x, int y, Table* table) : data(data), x(x), y(y), table(table) {};
	//Cell(const Cell& c) : data(c.data), x(c.x), y(c.y), table(c.table) {};
	Cell(int x, int y, Table* table) : x(x), y(y), table(table) {};
	Cell(const Cell& c) : x(c.x), y(c.y), table(c.table) {};

	virtual std::string stringify() = 0;
	virtual int to_numeric() = 0;
};

class StringCell : public Cell {
	std::string data;

public:
	std::string stringify();
	int to_numeric();
	StringCell(std::string data, int x, int y, Table* t) : data(data), Cell(x, y, t) {};
};


class NumberCell : public Cell {
	int data;

public:
	std::string stringify();
	int to_numeric();
	NumberCell(int data, int x, int y, Table* t) : data(data), Cell(x, y, t) {};
};


class DateCell : public Cell {
	time_t data;

public:
	std::string stringify();
	int to_numeric();
	DateCell(std::string s, int x, int y, Table* t);
};

class ExprCell : public Cell {
	std::string data;
	std::string* parsed_expression;
	MyExcel::Vector expression_vector;

	int precedence(char c);
	void parse_expression();

public:
	ExprCell(std::string data, int x, int y, Table* t)
		: data(data), Cell(x, y, t) {};
	std::string stringify();
	int to_numeric();
};
/* Cell definitions end */


class Table {
protected:
	int max_row_num, max_col_num;
	Cell*** data_table;

public:
	Table(int max_row_num, int max_col_num);
	Table(const Table& t) : max_row_num(t.max_row_num), max_col_num(t.max_col_num), data_table(t.data_table) {};
	~Table();

	int* address_parser(const std::string& address);
	void reg_cell(Cell* c, int row, int col);
	int to_numeric(const std::string& address);
	int to_numeric(int row, int col);

	std::string stringify(const std::string& address);
	std::string stringify(int row, int col);

	virtual std::string print_table() = 0;
};

class TxtTable : public Table {
	std::string repeat_char(int n, char c);
	std::string col_num_to_char(int n);

public:
	TxtTable(int row, int col) : Table(row, col) {};
	std::string print_table();
	void save_file(std::string file_name);
};

void txttable_test();
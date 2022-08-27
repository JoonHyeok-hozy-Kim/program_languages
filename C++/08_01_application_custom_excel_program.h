#include <string>
#include <iostream>

void vector_test();
void stack_test();
void num_stack_test();

class Table;
class Cell {
protected:
	int x, y;
	Table* table;
	std::string data;

public:
	Cell(std::string data, int x, int y, Table* table)
		: data(data), x(x), y(y), table(table) {};

	virtual std::string stringify();
	virtual int to_numeric();
};

class Table {
protected:
	int max_row_num, max_col_num;
	Cell*** data_table;

public:
	Table(int max_row_num, int max_col_num);
	~Table();

	int* address_parser(const std::string& address);
	void reg_cell(Cell* c, int row, int col);
	int to_numeric(const std::string& address);
	int to_numeric(int row, int col);

	std::string stringify(const std::string& address);
	std::string stringify(int row, int col);

	virtual std::string print_table() = 0;
};

void string_related_test();
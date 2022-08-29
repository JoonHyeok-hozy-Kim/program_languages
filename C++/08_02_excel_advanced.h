#include <string>
#include <iostream>
#include <fstream>

//class Table;
//class Cell {
//protected:
//	int x, y;
//	Table* table;
//
//public:
//	Cell(int x, int y, Table* table) : x(x), y(y), table(table) {};
//	Cell(const Cell& c) : x(c.x), y(c.y), table(c.table) {};
//
//	virtual std::string stringify() = 0;
//	virtual int to_numeric() = 0;
//};
//
//
//class StringCell : public Cell {
//	std::string data;
//
//public:
//	std::string stringify();
//	int to_numeric();
//	StringCell(std::string data, int x, int y, Table* t) : data(data), Cell(x, y, t) {};
//};
//
//
//class NumberCell : public Cell {
//	int data;
//
//public:
//	std::string stringify();
//	int to_numeric();
//	NumberCell(int data, int x, int y, Table* t) : data(data), Cell(x, y, t) {};
//};
//
//
//class DateCell : public Cell {
//	time_t data;
//
//public:
//	std::string stringify();
//	int to_numeric();
//	DateCell(std::string s, int x, int y, Table* t);
//};


void time_t_test();
void substr_test();
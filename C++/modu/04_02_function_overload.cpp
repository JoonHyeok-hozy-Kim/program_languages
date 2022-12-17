#include "04_02_function_overload.h"
#include <iostream>

void print(int i) { std::cout << i << std::endl; }
void print(char c) { std::cout << c << std::endl; }
void print(double d) { std::cout << d << std::endl; }

void overload_variables_test() {
	int i = 10;
	char c = 'A';
	double d = 12.23f;

	print(i);
	print(c);
	print(d);
}

void implicit_print(int i) { std::cout << i << std::endl; }
void implicit_print(double d) { std::cout << d << std::endl; }

void implicit_type_change_test() {
	char c = 'c';
	short s = 12;
	float f = 123.33f;
	enum {RED, BLUE, ORANGE};

	implicit_print(c);
	implicit_print(s);
	implicit_print(f);
	implicit_print(BLUE);
}


class Date2 {
private:
	int _year;
	int _month;
	int _date;

public:
	void set_date(int year, int month, int date);
	void add_days(int days);
	void add_months(int months);
	void add_years(int years);
	int get_current_month_total_dates(int year, int month);
	void show_date();
};

void Date2::set_date(int year, int month, int date) {
	_year = year;
	_month = month;
	_date = date;
}

void Date2::add_days(int days) {
	int max_days = get_current_month_total_dates(_year, _month);
	if (_date + days > max_days) {
		add_months(1);
		days -= max_days - _date + 1;
		_date = 1;
		add_days(days);
	}
	else _date += days;
}

void Date2::add_months(int months) {
	if (_month + months > 12) {
		add_years((_month + months) / 12);
		_month = (_month + months) % 12;
	}
	else _month += months;
}

void Date2::add_years(int years) {
	_year += years;
}

int Date2::get_current_month_total_dates(int year, int month) {
	int dates_by_months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2) {
		return dates_by_months[month - 1];
	}
	else {
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) return 29;
				else return 28;
			}
			else return 29;
		}
		else return 28;
	}
}

void Date2::show_date() {
	std::cout << _year << "/" << _month << "/" << _date << std::endl;
}

void date_test() {
	Date2 date;
	date.set_date(2020, 4, 3);
	//date.show_date();

	// Add years test
	date.add_years(2);
	//date.show_date();

	// Add months test
	date.add_months(4);
	//date.show_date();
	date.add_months(6);
	//date.show_date();
	date.add_months(38);
	//date.show_date();

	// Add days test
	date.add_days(10);
	//date.show_date();
	date.add_days(28);
	//date.show_date();

	Date2 date2;
	date2.set_date(2020, 8, 21);
	date2.add_days(10000);
	date2.show_date();
}
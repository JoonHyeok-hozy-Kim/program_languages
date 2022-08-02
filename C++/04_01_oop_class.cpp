#include <iostream>
#include "04_01_oop_class.h"

class Animal {
private:				// Accessible only within this class or the instance (Default setting for members and methods).
	int health;
	int weight;

public:					// Accessible in any instance
	void set_animal(int _health, int _weight) {
		health = _health;
		weight = _weight;
	}

	void feed(int food_amount) {
		health += food_amount * .1;
		weight += food_amount * .3;
	}

	void view_stat() {
		std::cout << "\nHealth : " << health << std::endl;
		std::cout << "Weight : " << weight << std::endl;
	}
};


void animal_class_test() {
	Animal herd[10];

	for (int i = 0; i < 10; i++) {
		herd[i].set_animal(100 + i, 50 + 2 * i);
	}

	for (int i = 0; i < 10; i++) {
		herd[i].view_stat();
	}

	for (int i = 0; i < 10; i++) {
		herd[i].feed(30);
	}

	for (int i = 0; i < 10; i++) {
		herd[i].view_stat();
	}
}

class Date {
	int year_;
	int month_;	// 1 ~ 12
	int date_;  // 1 ~ 31

public:
	void set_date(int year, int month, int date) {
		year_ = year;
		month_ = month;
		date_ = date;
	}

	void show_date() {
		std::cout << "Date : " << year_ << "/" << month_ << "/" << date_ << std::endl;
	}

	void add_year(int inc) {
		year_ += inc;
	}

	void add_month(int inc) {
		if (month_ + inc > 12) {
			add_year((month_ + inc) / 12);
			month_ = (month_ + inc) % 12;
		}
		else {
			month_ += inc;
		}
	}

	void add_date(int inc) {
		if (date_ + inc > 31) {
			add_month((date_ + inc) / 31);
			date_ = (date_ + inc) % 31;
		}
		else {
			date_ += inc;
		}
	}
};


void date_class_test() {
	Date date;
	date.set_date(2022, 8, 2);
	date.show_date();

	// add_year test
	date.add_year(3);
	date.show_date();

	// add_month test
	date.add_month(3);
	date.show_date();
	date.add_month(1);
	date.show_date();
	date.add_month(4);
	date.show_date();
	date.add_month(37);
	date.show_date();

	// add_date test
	date.add_date(20);
	date.show_date();
	date.add_date(19);
	date.show_date();
	date.add_date(21+31*6+5);
	date.show_date();
}
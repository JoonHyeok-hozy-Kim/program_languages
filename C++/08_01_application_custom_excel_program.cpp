#include "utilities.h"
#include "08_01_application_custom_excel_program.h"

void vector_test() {
	MyExcel::Vector v;
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
	MyExcel::Stack s;
	std::cout << "Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	for (int i = 0; i < 10; i++) {
		s.push(std::to_string(i));
		std::cout << "Pushed : " << s.peek() << " / Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << "Popped : " << s.pop() << " / Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	}
	std::cout << "Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
}

void num_stack_test() {
	MyExcel::NumStack s;
	std::cout << "Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	for (int i = 0; i < 10; i++) {
		s.push(i);
		std::cout << "Pushed : " << s.peek() << " / Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << "Popped : " << s.pop() << " / Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
	}
	std::cout << "Size : " << s.size() << " / is_empty : " << s.is_empty() << std::endl;
}

/* Cell starts. */
std::string Cell::stringify() { return data; }
int Cell::to_numeric() { return 0; }
/* Cell ends. */

/* Table starts. */
Table::Table(int max_row_num, int max_col_num)
	: max_row_num(max_row_num), max_col_num(max_col_num) {

	data_table = new Cell * *[max_row_num];
	for (int i = 0; i < max_row_num; i++) {
		data_table[i] = new Cell * [max_col_num];
		for (int j = 0; j < max_col_num; j++) {
			data_table[i][j] = NULL;
		}
	}
}

Table::~Table() {
	for (int i = 0; i < max_row_num; i++) {
		for (int j = 0; j < max_col_num; j++) {
			if (data_table[i][j]) delete data_table[i][j];
		}
	}
	for (int i = 0; i < max_row_num; i++) delete[] data_table[i];
	delete[] data_table;
}

void Table::reg_cell(Cell* c, int row, int col) {
	if (!(row < max_row_num && col < max_col_num)) return;
	if (data_table[row][col]) delete data_table[row][col];
	data_table[row][col] = c;
}

void string_related_test() {
	std::string address("Ax1");
	const char* c = address.c_str();
	char* d = (char*)c;
	bool alpha_flag = true;
	bool num_flag = false;
	int alpha_cnt = 0;
	for (int i = 0; i < (int)address.length(); i++) {
		if (isalpha(*d) && alpha_flag) {
			std::cout << "Alpha : " << *d << std::endl;
			alpha_cnt++;
		}
		else if (!isalpha(*d) && isalnum(*d)) {
			if (alpha_flag == num_flag) {
				std::cout << "Address parsing error at : " << *d << std::endl;
				return;
			}

			if (alpha_flag && !num_flag) {
				alpha_flag = false;
				num_flag = true;
			}
			std::cout << "Alnum : " << *d << std::endl;
		}
		else {
			std::cout << "Wrong address format : " << address << std::endl;
			return;
		}
		d++;
	}

	std::cout << "alpha_cnt : " << alpha_cnt << std::endl;
	int row = -1;
	//std::cout << "Row creation" << std::endl;
	for (int i = (int)address.length(); i > alpha_cnt; i--) {
		row += (int)std::pow(10, address.length() - i) * ((int)address[i - 1] - '0');
		//std::cout << row << std::endl;
	}

	int col = 0;
	std::cout << "Column creation" << std::endl;
	for (int j = 0; j < alpha_cnt; j++) {
		int digit = (int)std::pow(26, alpha_cnt-j-1);
		int temp;
		if (address[j] >= 'a' && address[alpha_cnt - 1] <= 'z') {
			temp = address[alpha_cnt - 1] - 'a';
		}
		else {
			temp = address[alpha_cnt - 1] - 'A';
		}
		if (j > 0) temp++;
		col += (digit * temp);
		std::cout << "digit : " << digit << " temp : " << temp << " col : " << col << std::endl;
	}

	int result[2];
	result[0] = row;
	result[1] = col;
	std::cout << "row : " << result[0] << " col : " << result[1] << std::endl;


}

int* Table::address_parser(const std::string& address) {
	//std::string address("A178");
	const char* c = address.c_str();
	char* d = (char*)c;
	bool alpha_flag = true;
	bool num_flag = false;
	int alpha_cnt = 0;
	for (int i = 0; i < address.length(); i++) {
		if (isalpha(*d) && alpha_flag) {
			std::cout << "Alpha : " << *d << std::endl;
			alpha_cnt++;
		}
		else if (!isalpha(*d) && isalnum(*d)) {
			if (alpha_flag == num_flag) {
				std::cout << "Address parsing error at : " << *d << std::endl;
				return NULL;
			}

			if (alpha_flag && !num_flag) {
				alpha_flag = false;
				num_flag = true;
			}
			std::cout << "Alnum : " << *d << std::endl;
		}
		else {
			std::cout << "Wrong address format : " << address << std::endl;
			return NULL;
		}
		d++;
	}

	std::cout << "alpha_cnt : " << alpha_cnt << std::endl;
	int row = -1;
	//std::cout << "Row creation" << std::endl;
	for (int i = (int)address.length(); i > alpha_cnt; i--) {
		row += (int)std::pow(10, address.length() - i) * ((int)address[i - 1] - '0');
		//std::cout << row << std::endl;
	}

	int col = 0;
	std::cout << "Column creation" << std::endl;
	for (int j = 0; j < alpha_cnt; j++) {
		int digit = (int) std::pow(26, j);
		int temp;
		if (address[alpha_cnt - 1] >= 'a' && address[alpha_cnt - 1] <= 'z') {
			temp = address[alpha_cnt - 1] - 'a';
		}
		else {
			temp = address[alpha_cnt - 1] - 'A';
		}
		if (j > 0) temp++;
		col += (digit * temp);
		std::cout << "digit : " << digit << " temp : " << temp << " col : " << col << std::endl;
	}

	int* result = new int[2];
	result[0] = row;
	result[1] = col;
	return result;
}

int Table::to_numeric(const std::string& address) {
	//int* num_address = address_parser(address);
	//std::cout << "row : " << num_address[0] << " col : " << num_address[1] << std::endl;

	return 0;
}

int Table::to_numeric(int row, int col) {
	return 0;
}


std::string Table::stringify(const std::string& address) {
	return "";
}

std::string Table::stringify(int row, int col) {
	return "";
}



/* Table ends. */
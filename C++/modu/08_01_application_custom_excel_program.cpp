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
//std::string Cell::stringify() { return data; }
//int Cell::to_numeric() { return 0; }

std::string StringCell::stringify() { return data; }
int StringCell::to_numeric() { return 0; }

std::string NumberCell::stringify() { return std::to_string(data); }
int NumberCell::to_numeric() { return data; }

std::string DateCell::stringify() {
	char buf[50];
	tm temp;
	localtime_s(&temp, &data);
	strftime(buf, 50, "%F", &temp);
	return std::string(buf);
}

int DateCell::to_numeric() { return static_cast<int>(data); }

DateCell::DateCell(std::string s, int x, int y, Table* t) : Cell(x, y, t) {
	// s in format : yyyy-mm-dd
	int year = std::atoi(s.c_str());
	int month = std::atoi(s.c_str() + 5);
	int date = std::atoi(s.c_str() + 8);

	tm timeinfo;
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = date;
	timeinfo.tm_hour = 0;
	timeinfo.tm_min = 0;
	timeinfo.tm_sec = 0;

	data = mktime(&timeinfo);
}

int ExprCell::precedence(char c) {
	switch (c) {
	case '(':
	case '[':
	case '{':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return 0;
}

void ExprCell::parse_expression() {
	MyExcel::Stack stack;

	data.insert(0, "(");
	data.append(")");

	for (int i = 0; i < data.length(); i++) {
		if (isalpha(data[i])) {
			// For the cell reference. TBD
		}
		else if (isdigit(data[i])) {
			expression_vector.push_back(data.substr(i, 1));
		}
		else if (data[i] == '(' || data[i] == '{' || data[i] == '[') {
			stack.push(data.substr(i, 1));
		}
		else if (data[i] == ')' || data[i] == '}' || data[i] == ']') {
			std::string t = stack.pop();
			while (t != "(" && t != "{" && t != "[") {
				expression_vector.push_back(t);
				t = stack.pop();
			}
		}
		else if (data[i] == '+' || data[i] == '-' || data[i] == '*' ||
			data[i] == '/') {
			while (!stack.is_empty() &&
				precedence(stack.peek()[0]) >= precedence(data[i])) {
				expression_vector.push_back(stack.pop());
			}
			stack.push(data.substr(i, 1));
		}
	}
}

std::string ExprCell::stringify() {
	return data;
}

int ExprCell::to_numeric() {
	double result = 0;
	MyExcel::NumStack stack;

	for (int i = 0; i < expression_vector.size(); i++) {
		std::string s = expression_vector[i];

		if (isalpha(s[0])) {
			// When reference to a cell. TBD
		}
		else if (isdigit(s[0])) {
			stack.push(atoi(s.c_str()));
		}
		else {
			double y = stack.pop();
			double x = stack.pop();
			switch (s[0]) {
			case '+':
				stack.push(x + y);
				break;
			case '-':
				stack.push(x - y);
				break;
			case '*':
				stack.push(x * y);
				break;
			case '/':
				stack.push(x / y);
				break;
			}
		}
	}
	return stack.pop();
}
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
	//std::cout << "reg_cell(" << row << "," << col << ") : " << data_table[row][col]->stringify() << std::endl;
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

	int col = -1;
	//std::cout << "Column creation" << std::endl;
	for (int j = 0; j < alpha_cnt; j++) {
		int digit = (int)std::pow(26, alpha_cnt - j - 1);
		int temp;
		if (address[j] >= 'a' && address[j] <= 'z') {
			temp = address[j] - 'a' + 1;
		}
		else {
			temp = address[j] - 'A' + 1;
		}
		col += (digit * temp);
		std::cout << address[j] << " -> digit : " << digit << " temp : " << temp << " col : " << col << std::endl;
	}

	int* result = new int[2];
	result[0] = row;
	result[1] = col;
	return result;
}

int Table::to_numeric(const std::string& address) {
	int* num_address = address_parser(address);
	int row = num_address[0];
	int col = num_address[1];
	if (row < max_row_num && col < max_col_num) {
		if (data_table[row][col]) {
			return data_table[row][col]->to_numeric();
		}
	}
	return 0;
}

int Table::to_numeric(int row, int col) {
	if (row < max_row_num && col < max_col_num) {
		if (data_table[row][col]) {
			return data_table[row][col]->to_numeric();
		}
	}
	return 0;
}


std::string Table::stringify(const std::string& address) {
	int* num_address = address_parser(address);
	int row = num_address[0];
	int col = num_address[1];
	if (row < max_row_num && col < max_col_num) {
		if (data_table[row][col]) {
			return data_table[row][col]->stringify();
		}
	}
	return "";
}

std::string Table::stringify(int row, int col) {
	if (row < max_row_num && col < max_col_num) {
		if (data_table[row][col]) {
			return data_table[row][col]->stringify();
		}
	}
	return "";
}
/* Table ends. */

/* TxtTable starts. */
std::string TxtTable::repeat_char(int n, char c) {
	std::string s = "";
	for (int i = 0; i < n; i++) s.push_back(c);
	return s;
}

std::string TxtTable::col_num_to_char(int n) {
	std::string s = "";
	n++;
	int cnt = 0;
	int powered = 1;
	int char_num = 26;
	while (true) {
		if (n > char_num * (powered - 1) / (char_num - 1)) {
			cnt++;
			powered *= char_num;
		}
		else break;
	}

	powered /= char_num;
	n -= char_num * (powered - 1) / (char_num - 1) + 1;

	for (int i = 0; i < cnt; i++) {
		char temp_char = 'A';
		temp_char += n / powered;
		s.push_back(temp_char);
		n %= powered;
		powered /= char_num;
	}

	return s;
}

std::string TxtTable::print_table() {
	std::string table_text;
	int first_col_size = 4;		// supports row number 1 ~ 10^4-1 (4 digits)

	int* col_max_width_list = new int[max_col_num];
	for (int j = 0; j < max_col_num; j++) {
		unsigned int max_width = 2;		// Default width 2.
		for (int i = 0; i < max_row_num; i++) {
			if (data_table[i][j] && data_table[i][j]->stringify().length() > max_width) {
				max_width = data_table[i][j]->stringify().length();
			}
		}
		col_max_width_list[j] = max_width;
	}

	// First line with column names.
	table_text.append(repeat_char(first_col_size, ' '));
	int line_total_width = first_col_size;
	for (int j = 0; j < max_col_num; j++) {
		table_text.append(" | ");
		line_total_width += 3;
		std::string col_num = col_num_to_char(j);
		table_text.append(col_num);
		table_text.append(repeat_char(col_max_width_list[j] - col_num.length(), ' '));
		line_total_width += col_max_width_list[j];
	}
	table_text.push_back('\n');

	table_text.append(repeat_char(line_total_width, '-'));
	table_text.push_back('\n');

	for (int i = 0; i < max_row_num; i++) {
		std::string row_num = std::to_string(i + 1);
		table_text.append(row_num);
		table_text.append(repeat_char(first_col_size - row_num.length(), ' '));

		for (int j = 0; j < max_col_num; j++) {
			table_text.append(" | ");
			int content_length = 0;
			if (data_table[i][j]) {
				//std::cout << data_table[i][j]->stringify() << std::endl;
				table_text.append(data_table[i][j]->stringify());
				content_length += data_table[i][j]->stringify().length();
			}
			table_text.append(repeat_char(col_max_width_list[j] - content_length, ' '));
		}
		table_text.push_back('\n');
	}

	std::cout << table_text << std::endl;

	return table_text;
}

void TxtTable::save_file(std::string file_name) {
	std::string table_text = print_table();
	file_name.append(".txt");
	std::ofstream fout(file_name.c_str());

	if (fout.is_open()) {
		fout << table_text;
		std::cout << "Saved successfully." << std::endl;
	}
	else {
		std::cout << "[Error] file not saved." << std::endl;
	}
	return;
}

/* TxtTable ends. */

void txttable_test() {
	int row = 50;
	int col = 15;
	TxtTable t(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::string s = std::to_string(i + j);
			t.reg_cell(new StringCell(s, i, j, &t), i, j);
		}
	}

	t.reg_cell(new StringCell("ABCccccc", 0, 0, &t), 0, 0);

	t.print_table();
	//t.save_file("08_01_excel_test");
}
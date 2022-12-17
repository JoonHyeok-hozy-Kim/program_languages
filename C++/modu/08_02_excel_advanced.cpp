#include "08_02_excel_advanced.h"

///* Cell classes' definitions start. */
//std::string StringCell::stringify() { return data; }
//int StringCell::to_numeric() { return 0; }
//
//std::string NumberCell::stringify() { return std::to_string(data); }
//int NumberCell::to_numeric() { return data; }
//
//std::string DateCell::stringify() { 
//	char buf[50];
//	tm temp;
//	localtime_s(&temp, &data);
//	strftime(buf, 50, "%F", &temp);
//	return std::string(buf);
//}
//
//int DateCell::to_numeric() { return static_cast<int>(data); }
//
//DateCell::DateCell(std::string s, int x, int y, Table* t) : Cell(x, y, t) {
//	// s in format : yyyy-mm-dd
//	int year = std::atoi(s.c_str());
//	int month = std::atoi(s.c_str() + 5);
//	int date = std::atoi(s.c_str() + 8);
//
//	tm timeinfo;
//	timeinfo.tm_year = year - 1900;
//	timeinfo.tm_mon = month - 1;
//	timeinfo.tm_mday = date;
//	timeinfo.tm_hour = 0;
//	timeinfo.tm_min = 0;
//	timeinfo.tm_sec = 0;
//
//	data = mktime(&timeinfo);
//}
///* Cell classes' definitions end. */


void time_t_test() {
	tm timeinfo;
	
	timeinfo.tm_year = 1993 - 1900;
	timeinfo.tm_mon = 4-1;
	timeinfo.tm_mday = 27;
	timeinfo.tm_hour = 0;
	timeinfo.tm_min = 0;
	timeinfo.tm_sec = 0;

	time_t data = mktime(&timeinfo);
	std::cout << static_cast<int>(data) << std::endl;

	char buf[50];
	tm temp;
	localtime_s(&temp, &data);
	strftime(buf, 50, "%F", &temp);
	std::cout << std::string(buf) << std::endl;
}

void substr_test() {
	std::string s("abcde123");

	/*std::cout << s.substr(0, 1) << std::endl;
	std::cout << s.substr(0, 2) << std::endl;
	std::cout << s.substr(0, 3) << std::endl;

	std::cout << s.substr(1, 1) << std::endl;
	std::cout << s.substr(1, 2) << std::endl;
	std::cout << s.substr(1, 3) << std::endl;*/

	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) std::cout << "isalpha : " << s[i] << std::endl;
		if (isdigit(s[i])) std::cout << "isdigit : " << s[i] << std::endl;
	}

}
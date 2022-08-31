#include "09_01_templates.h"

void template_vector_test() {

	TemplateVector<int> ti;
	for (int i = 0; i < 10; i++) {
		ti.push_back(i);
		//ti.print();
		std::cout << ti[i] << std::endl;
	}

	TemplateVector<std::string> ts;
	for (int i = 0; i < 10; i++) {
		std::string s = "";
		s.push_back((char)(i + 65));
		ts.push_back(s);
		//ts.print();
		std::cout << ts[i] << std::endl;
	}
}
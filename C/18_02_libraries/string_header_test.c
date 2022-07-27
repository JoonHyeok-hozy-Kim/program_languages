#include <stdio.h>
#include <string.h> // Library for string operations

void comparison_print(char* str1, char* str2);


void string_header_test() {

	char str1[20] = "abcd";
	char str2[20] = "efgh";

	comparison_print(str1, str2);
	strcpy(str1, str2);
	comparison_print(str1, str2);

}


void comparison_print(char* str1, char* str2) {

	printf("%s ", str1);
	if (strcmp(str1, str2) >= 0) {
		printf("== ");
	}
	else {
		printf("!= ");
	}
	printf("%s\n", str2);
};
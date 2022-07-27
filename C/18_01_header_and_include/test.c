#include <stdio.h>
#include "str_h.h"

int compare(char* str1, char* str2);

void main() {

	char* str1 = "abcd";
	char* str2 = "abcd";
	char* str3 = "abc";

	/* Call function from other c files */
	//printf("%s and %s are ", str1, str2);
	//if (compare(str1, str2)) { // compare() in str.c
	//	printf("identical.\n");
	//}
	//else {
	//	printf("different.\n");
	//}

	//printf("%s and %s are ", str1, str3);
	//if (compare(str1, str3)) {
	//	printf("identical.\n");
	//}
	//else {
	//	printf("different.\n");
	//}


	/* Call function from the header */
	char new_str[20];

	copy_str(new_str, str1);
	printf("%s", new_str);

	return;
}
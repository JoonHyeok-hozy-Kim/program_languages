#include <stdio.h>
#include <stdbool.h>

int str_len(char* str);
bool str_eq(char* str1, char* str2);


void main() {

	// Null-terminating string
	/*char null_1 = '\0';
	char null_2 = 0;
	char null_3 = (char)NULL;

	char not_null = '0';

	printf("NULL's ASCII code : %d, %d, %d \n", null_1, null_2, null_3);
	printf("'O''s ASCII code  : %d", not_null);*/


	//// String and Null
	//char word_1[4] = { 'd', 'o', 'g', '\0' };
	//char word_2[4] = { 'd', 'o', 'g', 0 };
	//char word_3[4] = { 'd', 'o', 'g', (char)NULL };
	//char word_4[4] = { "dog" }; // Additional space required for NULL in string

	//printf("word_1 : %s \n", word_1);
	//printf("word_2 : %s \n", word_2);
	//printf("word_3 : %s \n", word_3);
	//printf("word_4 : %s \n", word_4);


	// String with pointer
	/*char long_sentence[] = { "long sentence" };
	char* str = long_sentence;

	printf("%s \n", str);

	long_sentence[0] = 'a';
	long_sentence[1] = 'b';
	long_sentence[2] = 'c';
	long_sentence[3] = 'd';

	printf("%s \n", str);

	int i;
	for (i = 0; i < 4; i++) {
		printf("%c\n", str[i]);
	}*/


	// How to count the length of a string.
	/*char long_sentence[] = { "long" };
	int len;

	len = str_len(long_sentence);
	printf("%d", len);*/



	// Getting String Input
	/*char sentence[30];

	printf("Input 30 digit limit sentence : ");
	scanf("%s", &sentence);

	printf("%s", sentence);*/


	// Constant char without assigning an array
	/*const char* str = "abcdefg";
	printf("%s", str);*/


	// equality between strings.
	char str_a[] = "abc";
	char str_b[] = "ab";

	if (str_eq(str_a, str_b)) {
		printf("yes");
	}
	else {
		printf("no");
	}


}



int str_len(char* str) {
	int i=0;
	
	while (str[i]) {
		i++;
	}
	return i;
};

bool str_eq(char* str1, char* str2) {
	int i = 0;
	bool result = false;

	while (str1[i] || str2[i]) {
		if (str1[i] == str2[i]) {
			result = true;
			i++;
		}
		else {
			result = false;
			break;
		}
	}
	return result;
};
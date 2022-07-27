#include <stdio.h>

int str_copy(char* dest, char* src);
int concatenate(char* str1, char* str2);
int compare(char* str1, char* str2);

// Q1
int str_len(char* str);
void pad_100(char* str);
int reverse_100(char* str);

// Q2
void case_shift(char* str);

// Q4
int search_str(char* str1, char* str2);

void main() {

	char str[100] = "sentence";
	char* pstr = "sentence";

	/*printf("str[] : %s\n", str);
	printf("*pstr : %s\n", pstr);*/

	char dest[] = "abcdefghi";
	//printf("*dest : %s\n", dest);
	//str_copy(dest, pstr);
	//printf("*dest : %s\n", dest);

	/*char add_on[4] = "jhk";
	printf("str : %s\n", str);
	concatenate(str, add_on);
	printf("str : %s\n", str);*/


	/*char a[5] = "abcd";
	char b[5] = "abcd";
	char c[5] = "abc";

	printf("Result : %d\n", compare(a, b));
	printf("Result : %d\n", compare(a, c));*/


	// Q1
	/*char a[100] = "abcde";
	printf("%d\n", str_len(a));
	printf("%s\n", a);
	pad_100(a);
	printf("%d\n", str_len(a));
	printf("%s\n", a);
	reverse_100(a);*/


	// Q2
	/*char st[100] = "aBcDe";

	printf("%s\n", st);
	case_shift(st);
	printf("%s\n", st);*/

	
	// Q3
	/*char a[4] = "abc";
	char b[4] = "abc";
	char c[4] = "efg";

	printf("%d\n", compare(a, b));
	printf("%d\n", compare(a, c));*/


	// Q4
	char a[10] = "abcdefg";
	char b[4] = "efg";
	char c[4] = "ef1";

	printf("%d\n", search_str(a, b));
	printf("%d\n", search_str(a, c));
}


int str_copy(char* dest, char* src) {

	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\n';
	return 1;
};

int concatenate(char* str1, char* str2) {

	while (*str1) {
		str1++;
	}
	while (*str2) {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return 0;
};


int compare(char* str1, char* str2) {

	while (*str1) {
		if (*str1 != *str2) {
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2) {
		return 0;
	}
	else {
		return 1;
	}

};


// Q1
int str_len(char* str) {
	int result = 0;
	while (*str) {
		result++;
		str++;
	}
	return result;
};

void pad_100(char* str) {
	int i, j, cnt=0;
	while (*str) {
		cnt++;
		str++;
	}
	for (i = 0; i < 99-cnt; i++) {
		j = 65 + i % 26;
		*str = j;
		str++;
	}
	*str = '\0';
};

int reverse_100(char* str) {
	int i, len;
	len = str_len(str);
	str += len;
	for (i = 0; i <= len; i++) {
		printf("%c", *str);
		str--;
	}
	
	return 0;
};


// Q2
void case_shift(char* str) {
	while (*str) {
		if (*str >= 65 && *str <= 90) {
			*str += 32;
		}
		else if (*str >= 97 && *str <= 122) {
			*str -= 32;
		}
		str++;
	}
};


// Q4
int search_str(char* str1, char* str2) {
	int start=0, cnt=0;

	while (*str1) {
		if (cnt == 0 && *str1 == *str2) {
			while (*str2) {
				if (*str1 == *str2) {
					cnt++;
					str1++;
					str2++;
				}
				else {
					str1 -= cnt;
					str2 -= cnt;
					cnt = 0;
					break;
				}
			}
		}
		if (cnt > 0) {
			return start;
		}
		else {
			start++;
			str1++;
		}
	}
	return -1;
};
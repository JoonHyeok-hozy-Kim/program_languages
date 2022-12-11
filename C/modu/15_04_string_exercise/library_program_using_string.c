#include <stdio.h>

int add_book(int new_book_no, char(*titles)[30], char(*authors)[30], char(*publishers)[30]);
void show_book_info(int book_no, char(*titles)[30], char(*authors)[30], char(*publishers)[30], int* book_status);
int search_book_by_title(char (*titles)[30], int book_len);
int search_book_by_author(char (*authors)[30], int book_len);
int search_book_by_publisher(char (*publishers)[30], int book_len);
int str_eq(char* str1, char* str2);
int borrow_book(int *book_status);
int return_book(int* book_status);
void print_list(int book_len, char(*titles)[30], char(*authors)[30], char(*publishers)[30], int* book_status);
void print_space(int num);
void print_str(char* pstr, int len);
int digit_count(int num);

int main() {
	int choice, book_no=0, search_result;
	int book_status[100] = { 0 };
	char titles[100][30], authors[100][30], publishers[100][30];

	while (1) {

		printf("\nPlease choose the job.\n");
		printf("  1. Add a book.\n");
		printf("  2. Search book by title.\n");
		printf("  3. Search book by author.\n");
		printf("  4. Search book by publisher.\n");
		printf("  5. Borrow book.\n");
		printf("  6. Return book.\n");
		printf("  7. Exit.\n");
		printf("  8. Show book list.\n");
		printf("Job No : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			book_no = add_book(book_no, titles, authors, publishers);
			break;
		case 2:
			search_result = search_book_by_title(titles, book_no+1);
			show_book_info(search_result, titles, authors, publishers, book_status);
			break;
		case 3:
			search_result = search_book_by_author(authors, book_no + 1);
			show_book_info(search_result, titles, authors, publishers, book_status);
			break;
		case 4:
			search_result = search_book_by_publisher(publishers, book_no + 1);
			show_book_info(search_result, titles, authors, publishers, book_status);
			break;
		case 5:
			borrow_book(book_status);
			break;
		case 6:
			return_book(book_status);
			break;
		case 7:
			printf("Bye~");
			return 0;
		case 8:
			print_list(book_no, titles, authors, publishers, book_status);
			break;
		default:
			printf("Wrong number : %d\n", choice);
		}


	}


}

int add_book(int new_book_no, char(*titles)[30], char(*authors)[30], char(*publishers)[30]) {
	//char title[30], author[30], publisher[30];

	printf("\n[Add book]\n");
	printf("Book Title : ");
	scanf("%s", &titles[new_book_no]);
	printf("Author Name : ");
	scanf("%s", &authors[new_book_no]);
	printf("Publisher Name : ");
	scanf("%s", &publishers[new_book_no]);
	printf("book added.\n");
	
	return new_book_no + 1;
};

void show_book_info(int book_no, char(*titles)[30], char(*authors)[30], char(*publishers)[30], int* book_status) {
	int i;

	if (book_no < 0) {
		printf("Search failure.\n");
		return;
	}
	for (i = 0; i < book_no; i++) {
		titles++;
		authors++;
		publishers++;
		book_status++;
	}
	printf("\n----<< Search Result >>----\n", *titles);
	printf("Book No.  : %d\n", book_no);
	printf("Title     : %s\n", *titles);
	printf("Author    : %s\n", *authors);
	printf("Publisher : %s\n", *publishers);
	if (*book_status < 0) {
		printf("Status    : Not Available\n");
	}
	else {
		printf("Status    : Available\n");
	}
	printf("---------------------------\n");
};

int search_book_by_title(char (*titles)[30], int book_len) {
	int book_no;
	char title[30];

	if (book_len < 1) {
		return -1;
	}

	printf("\n[Search book by title]\n");
	printf("Book title : ");
	scanf("%s", &title);

	for (book_no = 0; book_no < book_len; book_no++) {
		//printf("In titles, %s\n", *titles);
		if (str_eq(*titles, title) > 0) {
			return book_no;
		}
		titles++;
	}
	return -1;
};

int search_book_by_author(char (*authors)[30], int book_len) {
	int book_no;
	char author[30];

	if (book_len < 1) {
		return -1;
	}

	printf("\n[Search book by author]\n");
	printf("Book author : ");
	scanf("%s", &author);

	for (book_no = 0; book_no < book_len; book_no++) {
		if (str_eq(*authors, author) > 0) {
			return book_no;
		}
		authors++;
	}
	return -1;
};

int search_book_by_publisher(char (*publishers)[30], int book_len) {
	int book_no;
	char publisher[30];

	if (book_len < 1) {
		return -1;
	}

	printf("\n[Search book by publisher]\n");
	printf("Book publisher : ");
	scanf("%s", &publisher);

	for (book_no = 0; book_no < book_len; book_no++) {
		if (str_eq(*publishers, publisher) > 0) {
			return book_no;
		}
		publishers++;
	}
	return -1;
};

int str_eq(char* str1, char* str2) {
	//printf("In str_eq\n");
	
	while (*str1) {
		//printf("In str_eq, %c vs %c\n", *str1, *str2);
		if (*str1 != *str2) {
			return 0;
		}
		else {
			str1++;
			str2++;
		}
	}
	if (*str2) {
		return 0;
	}
	else {
		return 1;
	}
};

int borrow_book(int* book_status) {
	int i, book_no;
	printf("Enter Book No. : ");
	scanf("%d", &book_no);
	
	for (i = 0; i < book_no; i++) {
		book_status++;
	}

	if (*book_status < 0) {
		printf("Book not available.\n");
		return -1;
	}
	else {
		*book_status = -1;
		printf("Successfully borrowed.\n");
		return 0;
	}
};

int return_book(int* book_status) {
	int i, book_no;
	printf("Enter Book No. : ");
	scanf("%d", &book_no);

	for (i = 0; i < book_no; i++) {
		book_status++;
	}

	if (*book_status < 0) {
		*book_status = 0;
		printf("Successfully returned.\n");
		return 0;
	}
	else {
		printf("Book cannot be returned.\n");
		return -1;
	}

};

void print_list(int book_len, char(*titles)[30], char(*authors)[30], char(*publishers)[30], int* book_status) {
	int i;

	printf("No.");
	print_space(2);
	printf("Title");
	print_space(25);
	printf("Author");
	print_space(24);
	printf("Publisher");
	print_space(21);
	printf("Availablity");
	printf("\n");

	for (i = 0; i < book_len; i++) {
		printf("%d", i + 1);
		print_space(5 - digit_count(i + 1));
		print_str(*titles, 30);
		print_str(*authors, 30);
		print_str(*publishers, 30);
		if (*book_status < 0) {
			printf("X");
		}
		else {
			printf("O");
		}
		printf("\n");
		titles++;
		authors++;
		publishers++;
		book_status++;
	}
};

void print_space(int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf(" ");
	}
};

void print_str(char* pstr, int len) {
	int i, cnt = 0;
	while (*pstr) {
		printf("%c", *pstr);
		cnt++;
		*pstr++;
	}
	for (i = 0; i < len - cnt; i++) {
		printf(" ");
	}
};



int digit_count(int num) {
	int cnt = 1;
	while (num >= 10) {
		num /= 10;
		cnt++;
	}
	return cnt;
};
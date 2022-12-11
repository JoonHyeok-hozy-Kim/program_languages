#include <stdio.h>
#include "str.h"
#include "book_management.h"

struct Book {
	int id;
	char title[30];
	char author[30];
	char publisher[30];
	int borrowed;
};

void book_management() {
	struct Book book_list[100];
	int book_cnt = 0;
	int choice = 9999;
	while (choice > 0) {
		printf("\nChoose job.\n");
		printf(" 1. Show book status.\n");
		printf(" 2. Add book.\n");
		printf(" 3. Find book by title.\n");
		printf(" 4. Find book by author name.\n");
		printf(" 5. Find book by publisher name.\n");
		printf(" 6. Borrow book.\n");
		printf(" 7. Return book.\n");
		printf(" 0. Exit.\n");
		printf("\Job Number : ");
		scanf("%d", &choice);

		printf("\n");
		switch (choice) {
		case 1:
			display_book_status(book_list, book_cnt);
			break;

		case 2:
			book_cnt = add_book(book_list, &book_cnt)+1;
			break;

		case 3:
			find_book_by_n(book_list, book_cnt, 1);
			break;

		case 4:
			find_book_by_n(book_list, book_cnt, 2);
			break;

		case 5:
			find_book_by_n(book_list, book_cnt, 3);
			break;

		case 6:
			borrow_book(book_list, book_cnt);
			break;

		case 7:
			return_book(book_list, book_cnt);
			break;

		case 0:
			printf("Bye~");
		}
	}
}

void display_book_status(struct Book* book_list, int book_cnt) {
	int i;

	printf("< Book Status>\n");
	if (book_cnt == 0) {
		printf("No book found. Please add book.\n");
	}
	else {

		fixed_length_string_display("ID", 4);
		fixed_length_string_display("Title", 31);
		fixed_length_string_display("Author", 31);
		fixed_length_string_display("Publisher", 31);
		fixed_length_string_display("Availablity", 11);
		printf("\n");

		for (i = 0; i < book_cnt; i++) {
			printf("%3d ", book_list[i].id);
			fixed_length_string_display(book_list[i].title, 31);
			fixed_length_string_display(book_list[i].author, 31);
			fixed_length_string_display(book_list[i].publisher, 31);
			if (book_list[i].borrowed) {
				fixed_length_string_display("X", 11);
			}
			else {
				fixed_length_string_display("O", 11);
			}
			printf("\n");
		}
	}
};

int add_book(struct Book* book_list, int* book_cnt) {
	char temp_text[100];
	int book_id = *book_cnt;

	printf("Add book. Please input book info.\n");

	// ID
	book_list[book_id].id = book_id;

	// Title
	printf("Book Title : ");
	scanf("%s", &temp_text);
	copy_str(book_list[book_id].title, temp_text);

	// Author
	printf("Author : ");
	scanf("%s", &temp_text);
	copy_str(book_list[book_id].author, temp_text);

	// TitlPublishere
	printf("Publisher : ");
	scanf("%s", &temp_text);
	copy_str(book_list[book_id].publisher, temp_text);

	// borrowed
	book_list[book_id].borrowed = 0;

	return book_id;
};

void find_book_by_n(struct Book* book_list, int book_cnt, int n) {
	struct Book search_result_list[100];
	char temp_text[30];
	char* search_target;
	int i, search_cnt=0;

	switch (n) {
	case 1:
		printf("Search book by title.\n");
		printf("Input title : ");
		break;
	case 2:
		printf("Search book by author.\n");
		printf("Input author name : ");
		break;
	case 3:
		printf("Search book by publisher.\n");
		printf("Input publisher name : ");
		break;
	default:
		break;
	}

	scanf("%s", &temp_text);

	for (i = 0; i < book_cnt; i++) {

		if (n == 1) { search_target = book_list[i].title; }
		else if (n == 2) { search_target = book_list[i].author; }
		else if (n == 3) { search_target = book_list[i].publisher; }

		if (include_str(search_target, temp_text)) {
			search_result_list[search_cnt] = book_list[i];
			search_cnt++;
		}
	}

	if (search_cnt==0) {
		printf("No book found.\n");
	}
	else {
		display_book_status(search_result_list, search_cnt);
	}
}

void display_available_books(struct Book* book_list, int book_cnt) {
	struct Book search_result_list[100];
	int i, cnt=0;
	for (i = 0; i < book_cnt; i++) {
		if (book_list[i].borrowed == 0) {
			search_result_list[cnt] = book_list[i];
			cnt++;
		}
	}
	display_book_status(search_result_list, cnt);
}

int borrow_book(struct Book* book_list, int book_cnt) {
	int book_id, i;

	display_available_books(book_list, book_cnt);

	printf("\nFind book from above and input BOOK_ID : ");
	scanf("%d", & book_id);
	for (i = 0; i < book_cnt; i++) {
		if (book_list[i].id == book_id) {
			if (book_list[i].borrowed) {
				printf("Book not available.\n");
				return 0;
			}
			else {
				book_list[i].borrowed = 1;
				printf("Successfully borrowed %s.\n", book_list[i].title);
				return 1;
			}
		}
	}
	printf("Wrong BOOK_ID.\n");
	return 0;
};

int return_book(struct Book* book_list, int book_cnt) {
	int book_id, i;
	printf("Input BOOK_ID of the book that will be returnded : ");
	scanf("%d", &book_id);
	for (i = 0; i < book_cnt; i++) {
		if (book_list[i].id == book_id) {
			if (book_list[i].borrowed) {
				book_list[i].borrowed = 0;
				printf("Successfully returned %s.\n", book_list[i].title);
				return 1;
			}
			else {
				break;
			}
		}
	}
	printf("Wrong BOOK_ID.\n");
	return 0;
}
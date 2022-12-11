#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
	int id;
	char book_name[30];
	char auth_name[30];
	char publ_name[30];
	int borrowed;
} Book;


int library_run();
int register_book(Book* book_list, int* nth);
int search_book(Book* book_list, int total_num_book);
int borrow_book(Book* book_list);
int return_book(Book* book_list);
void print_book_info(Book* book_list, int book_id);
int print_book_list(Book* book_list, int num_total_book);
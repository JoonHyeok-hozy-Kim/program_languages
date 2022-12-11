#include <stdio.h>
struct TEST {
	int c;
};
struct POINTER_TEST {
	int c;
	int* p;
};
struct STR_TEST {
	int c;
	char str[30];
};
struct HUMAN {
	int age;
	int gender;
	char name[30];
};

void struct_review();
void struct_with_pointer_var();
void function_with_sturct_var_input();
void add_one(int* a);
void assign_struct();
char copy_str(char* dest, char *src);
void str_copy_test();
void test_set_default_struct();
void set_default_struct(struct TEST *a, int c);
void set_default_human(struct HUMAN* h, int age, int gender, char* name);
void test_human();

// Q1
struct Book {
	int id;
	char title[30];
	char author[30];
	char publisher[30];
	int borrowed;
};

void run_book_management();
void register_book(struct Book *book, int id);
//int search_by_title(struct BOOK* book_list, char* title, int book_cnt);
int str_compare(char* str1, char* str2);


void main() {

	/*Breif Review of Structure*/
	//struct_review();

	/*Struct with point variable*/
	//struct_with_pointer_var();

	/*Struct Var as function input*/
	//function_with_sturct_var_input();

	/*Assigning struct with struct*/
	//assign_struct();

	/*String Variable Copy*/
	//str_copy_test();

	/*struct pointer as function input*/
	//test_set_default_struct();

	/*application*/
	//test_human();

	/* Q1 */
	run_book_management();
}


void struct_review() {
	struct TEST t;
	struct TEST* pt = &t;

	(*pt).c = 0;
	printf("%d\n", (*pt).c);
	pt->c = 1;
	printf("%d\n", (*pt).c);
};


void struct_with_pointer_var() {
	struct POINTER_TEST pt;
	struct POINTER_TEST* ppt = &pt;
	int i = 0;

	pt.p = &i;
	printf("i : %d\n", i);

	*pt.p = 4;
	printf("i : %d\n", i);

	*ppt->p = 6;
	printf("i : %d\n", i);

};

void function_with_sturct_var_input() {
	struct TEST t;
	struct TEST* pt=&t;
	pt->c = 0;
	printf("%d\n", t.c);
	add_one(&t.c);
	printf("%d\n", t.c);
	add_one(&pt->c);
	printf("%d\n", t.c);
};

void add_one(int* a) {
	(*a)++;
	return;
};

void assign_struct() {
	struct POINTER_TEST st1, st2;
	int i = 0;
	st1.c = 10;
	st1.p = &i;

	st2 = st1;
	printf("st2.c = %d, *(st2.p) = %d\n", st2.c, *(st2.p));
	
	st2.c++;
	i++;
	printf("st2.c = %d, *(st2.p) = %d\n", st2.c, *(st2.p));

	st1.c++;
	(*st2.p)++;
	printf("st2.c = %d, *(st2.p) = %d\n", st2.c, *(st2.p));

	add_one(&st2.c);
	add_one(st2.p);
	printf("st2.c = %d, *(st2.p) = %d\n", st2.c, *(st2.p));

};

char copy_str(char* dest, char* src) {
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return 1;
};

void str_copy_test() {
	struct STR_TEST a, b;
	a.c = 10;
	copy_str(a.str, "hello, world!");

	printf("%s\n", a.str);
	b = a;
	printf("%s\n", b.str);
};

void test_set_default_struct() {

	struct TEST ts;
	set_default_struct(&ts, 19);
	printf("%d\n", ts.c);
	set_default_struct(&ts, 20);
	printf("%d\n", ts.c);
};


void set_default_struct(struct TEST* a, int c) {
	a->c = c;
	return;
};


void set_default_human(struct HUMAN* h, int age, int gender, char* name) {

	h->age = age;
	h->gender = gender;
	copy_str(h->name, name);
	return;

};

void test_human() {

	struct HUMAN ape;
	set_default_human(&ape, 10, 1, "chimp");
	printf("Name : %s / Age : %d / Gender : %d\n", ape.name, ape.age, ape.gender);
};



void run_book_management() {
	struct Book book_list[100];
	int choice, book_cnt=0;

	while (1) {
		printf("\n< Job List >\n");
		printf("1. Print book list.\n");
		printf("2. Register book.\n");

		printf("0. Exit.\n");
		printf("Choose the job number : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			print_book_list(&book_list, book_cnt);
			break;
		case 2:
			register_book(&book_list[book_cnt], book_cnt);
			break;

		case 0:
			printf("Bye~\n");
			return;
		default:
			printf("Wrong number input!!!");
			break;
		}
	}
};

void register_book(struct Book* book, int id) {
	char title[30], author[30], publisher[30];
	printf("Title : ");
	scanf("%s", &title);
	printf("Author Name : ");
	scanf("%s", &author);
	printf("Publisher : ");
	scanf("%s", &publisher);
	

	printf("Title : %s, Author Name : %s, Publisher : %s\n", title, author, publisher);
	book->id = id;
	copy_str(book->title, title);
	copy_str(book->author, author);
	copy_str(book->publisher, publisher);
	book->borrowed = 0;

	return;

};



int str_compare(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return -1;
		}
		str1++;
		str2++;
	}
	if (*str2) {
		return -1;
	}
	else {
		return 0;
	}	
};
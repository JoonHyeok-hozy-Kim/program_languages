#include <stdio.h>
struct Book {
	char title[30];
	char author[30];
	char publisher[30];
	int borrowed;
};

struct test {
	int a, b;
};

void struct_test();
int copy_str(char* dest, char* src);
void struct_pointer_test();

void main() {

	//// Structure Test
	//struct_test();

	//// Structure Pointer Test
	struct_pointer_test();

}


void struct_test() {
	struct Book books[2];
	int i;
	
	for (i = 0; i < 2; i++) {
		
		copy_str(books[i].title, "Top Gun");
		copy_str(books[i].author, "Tony Scott");
		copy_str(books[i].publisher, "Paramount");
		books[i].borrowed = 1;
		
	}


	for (i = 0; i < 2; i++) {

		printf("Title : %s\n", books[i].title);
		printf("Author : %s\n", books[i].author);
		printf("Publisher : %s\n", books[i].publisher);
		printf("Borrowed : %d\n", books[i].borrowed);
	}

}


int copy_str(char* dest, char* src) {
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
};


void struct_pointer_test() {
	struct test ts;
	struct test* pts;

	pts = &ts;
	pts->a = 1;
	pts->b = 2;

	printf("[ts]  a : %d, b : %d\n", ts.a, ts.b);
	printf("[pts] a : %d, b : %d\n", (*pts).a, (*pts).b);
	printf("[pts] a : %d, b : %d\n", pts->a, pts->b);
};
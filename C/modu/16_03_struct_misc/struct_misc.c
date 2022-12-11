#include <stdio.h>

struct employee {
	char name[30];
	int age;
	int salary;
};

struct company {
	struct employee employee;
	char name[30];
};


void struct_in_struct_test();
void str_copy(char* str1, char* str2);
void function_struct_return_test();
struct employee employee_creator(char* name, int age, int sal);


void struct_definition_test();
struct obj {
	char name[30];
	int x, y;
} Ball;
void print_obj_status(struct obj OBJ);


union u {
	int i;
	char j;
};
void union_test();

union n {
	int i;
	short j;
	float k;
};
void little_endian_test();


enum { RED, BLUE, WHITE, BLACK };
enum { MALE=100, FEMALE };
void enum_test();


void main() {

	/* Struct in Struct Test */
	//struct_in_struct_test();

	/* Function that returns struct */
	//function_struct_return_test();

	/* Struct Definition */
	//struct_definition_test();

	/* Union */
	//union_test();

	/* Little Endian Test */
	//little_endian_test();

	/* enum TEST */
	enum_test();

}


void struct_in_struct_test() {

	struct company coke;

	str_copy(&coke.name, "Coka-Cola");
	str_copy(&coke.employee.name, "Kim");
	coke.employee.age = 20;
	coke.employee.salary = 100;

	printf("Company Name  : %s\n", coke.name);
	printf("Employee Name : %s\n", coke.employee.name);
	printf("Employee Age  : %d\n", coke.employee.age);
	printf("Employee Sal. : %d\n", coke.employee.salary);


};


void str_copy(char* str1, char* str2) {

	while (*str2) {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
};

void function_struct_return_test() {
	struct employee ee;
	char name[30] = "AJ";

	ee = employee_creator(&name, 29, 1000);
	printf("%s\n", ee.name);
	printf("%d\n", ee.age);
	printf("%d\n", ee.salary);
};

struct employee employee_creator(char* name, int age, int sal) {
	struct employee e;

	str_copy(e.name, name);
	e.age = age;
	e.salary = sal;

	return e;
};


void struct_definition_test() {
	str_copy(Ball.name, "RED BALL");
	Ball.x = 10;
	Ball.y = 20;

	print_obj_status(Ball);
};

void print_obj_status(struct obj OBJ) {
	printf("Name : %s\n", OBJ.name);
	printf(" ( %d , %d ) \n", OBJ.x, OBJ.y);
};

void union_test() {
	union u u1;
	u1.i = 0x12345678;
	printf("%x\n", u1.j);
	printf("%c\n", u1.j);
};


void little_endian_test() {
	union n n1;
	n1.i = 0x12345678;
	printf("%x\n", n1.i);
	printf("%x\n", n1.j);
	printf("%x\n", n1.k);

	n1.k = 0.1;
	printf("%x\n", n1.i);
	printf("%x\n", n1.j);
	printf("%x\n", n1.k);

};

void enum_test() {

	int pallete = WHITE;
	printf("%d\n", pallete);

	int gender = MALE;
	printf("%d\n", gender);

};
#include <stdio.h>

struct HUMAN {

	int age;
	int height;
	int weight;
	int gender;

};

typedef struct HUMAN Human;  // typedef
int print_status(Human human);
void typedef_test();


typedef int CAL_TYPE;
//typedef float CAL_TYPE;
void calculator_simulation();


void various_typedef_test();
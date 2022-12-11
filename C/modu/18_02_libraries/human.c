#include <stdio.h>
#include <string.h>
#include "human.h"

struct Human create_human(char* name, int age, int gender) {
	struct Human new_human;

	strcpy(new_human.name, name);
	new_human.age = age;
	new_human.gender = gender;

	return new_human;
}

void show_human_info(struct Human* human) {

	printf("\n [Human Info] \n");
	printf(" - Name   : %s\n", human->name);
	printf(" - Age    : %d\n", human->age);
	printf(" - Gender : ");
	if (human->gender) {
		printf("Female\n");
	}
	else {
		printf("Male\n");
	}
};

void human_struct_test() {
	struct Human society[20];
	char name_char = 'A';
	char name[20];
	int i;
	
	for (i = 0; i < 20; i++) {
		name[0] = name_char;
		name[1] = '\0';
		society[i] = create_human(name, i + 20, i % 2);
		name_char++;
	}

	for (i = 0; i < 20; i++) {
		show_human_info(&society[i]);
	}
}
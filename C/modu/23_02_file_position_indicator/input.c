#include "input.h"

void read_file(char* file_name) {
	FILE* file;
	char c;
	char* file_name_corrected;

	file_name_corrected = file_name_check(file_name);
	file = fopen(file_name_corrected, "r");

	if (file == NULL) {
		printf("File read error.\n");
	}

	while ((c = fgetc(file)) != EOF) {
		printf("%c", c);
	}

	fclose(file);
	return;
}

char* file_name_check(char* file_name) {
	int i;
	int name_correct = 0;
	char* temp_pointer = file_name;

	while (*temp_pointer) {
		temp_pointer++;
	}
	
	temp_pointer--;
	if (*temp_pointer == 't') {
		temp_pointer--;
		if (*temp_pointer == 'x') {
			temp_pointer--;
			if (*temp_pointer == 't') {
				temp_pointer--;
				if (*temp_pointer == '.') {
					name_correct = 1;
				}
			}
		}
	}

	if (name_correct) {
		return file_name;
	}
	else {
		char* new_name = (char*)malloc((int)(sizeof(file_name))+4);
		strcpy(new_name, file_name);
		strcat(new_name, ".txt");
		return new_name;
	}
}


void fscanf_test(char* file_name) {

	char* file_name_corrected = file_name_check(file_name);
	FILE* file = fopen(file_name_corrected, "r");
	char data[100];
	int i = 1;

	while (fscanf(file, "%s", data) != EOF) {
		printf("\nLine %d : ", i++);
		printf("%s", data);
	}

	return;
}
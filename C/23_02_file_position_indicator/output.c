#include "output.h"

FILE* create_txt_file(char* file_name, char* contents) {
	char full_name[50];
	FILE* file;

	strcpy(full_name, file_name);
	strcat(full_name, ".txt");

	file = fopen(&full_name, "w");

	if (file == NULL) {
		printf("File creation error.\n");
		return NULL;
	}

	fputs(contents, file);
	fclose(file);

	return file;
}
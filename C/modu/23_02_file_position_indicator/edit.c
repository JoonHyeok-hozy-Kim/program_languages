#include "edit.h"


FILE* overwrite_file(char* file_name, char* contents, int starting_digit) {
	char* corrected_name = file_name_check(file_name);
	FILE* file = fopen(corrected_name, "r+");
	int i;
	char c;

	if (file == NULL) {
		printf("File open error.\n");
		return NULL;
	}

	fseek(file, starting_digit, SEEK_SET);
	fputs(contents, file);
	fclose(file);

	return file;
}

FILE* case_shifter(char* file_name) {

	char* corrected_name = file_name_check(file_name);
	FILE* file = fopen(corrected_name, "r+");
	char c;

	while ((c = fgetc(file)) != EOF) {
		if (c >= 65 && c <= 90) {
			fseek(file, -1, SEEK_CUR);
			fputc(c + 32, file);
			fseek(file, 0, SEEK_CUR); // Call fseek again after fputs!!! Obligatory!!!
		}
		else if (c >= 97 && c <= 122) {
			fseek(file, -1, SEEK_CUR);
			fputc(c - 32, file);
			fseek(file, 0, SEEK_CUR); // Call fseek again after fputs!!! Obligatory!!!
		}
	}

	fclose(file);

	return file;
};


FILE* append_content(char* file_name, char* appending_content) {

	char* corrected_name = file_name_check(file_name);
	FILE* file = fopen(corrected_name, "a");  // Appending
	
	fputs(appending_content, file);
	fclose(file);

}
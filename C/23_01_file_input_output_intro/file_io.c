#include <stdio.h>

void file_output_test() {

	FILE* fp;
	fp = fopen("a.txt", "w");  // Returns the pointer pointing at the stream!

	if (fp == NULL) {
		printf("Write Error!!\n");
		return;
	}
	fputs("Hello World!!!\n", fp);
	fclose(fp);

	//fclose(stdout); // Experiment of closing standard stream
	

	return;

}


void file_input_test() {

	FILE* fp = fopen("a.txt", "r");
	char buf[20];
	if (fp == NULL) {
		printf("READ ERROR!\n");
	}
	
	fgets(buf, 20, fp);
	printf("INPUT : %s\n", buf);
	fclose(fp);
	return;
}


void read_file_by_char() {

	FILE* fp = fopen("a.txt", "r");
	char c;

	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
	}

	fclose(fp);
	return;
}


void file_size_test() {
	FILE* fp = fopen("a.txt", "r");
	printf("size : %d", file_size(fp));
	fclose(fp);
	return;
}

int file_size(FILE* fp) {
	int size = 0;
	while (fgetc(fp) != EOF) {
		size++;
	}
	return size;
}


void fseek_test() {

	FILE* fp = fopen("a.txt", "r");
	int i;
	
	for (i = 0; i < 4; i++) {
		printf("%c", fgetc(fp));
	}

	printf("\n");
	fseek(fp, 0, SEEK_SET);


	for (i = 0; i < 5; i++) {
		printf("%c", fgetc(fp));
	}

	printf("\n");
	fseek(fp, 2, SEEK_CUR);

	for (i = 0; i < 3; i++) {
		printf("%c", fgetc(fp));
	}

	printf("\n");
	fseek(fp, -6, SEEK_END);

	for (i = 0; i < 3; i++) {
		printf("%c", fgetc(fp));
	}
}
#include "output.h"
#include "input.h"
#include "edit.h"
#pragma once

void main(int argc, char** argv) {

	/* File creating and Reading Test */
	//file_name = "test_file2";
	//contents = "Finally the file creation and reading work!\n";
	//create_txt_file(file_name, contents);
	//read_file(file_name);


	/* Overwriting Test */
	//overwrite_file(file_name, "XXXXXXX", 3);
	//read_file(file_name);


	/* Case Shift Example */
	///char* file_name = "case_shift_test";
	///char* contents = "AbCdEfGh";
	///FILE* new_file = create_txt_file(file_name, contents);
	///read_file(file_name);
	///case_shifter(file_name);
	///printf("\n");
	///read_file(file_name);


	/* Append Contents */
	//char* file_name = "appending_test";
	//char* contents = "AbCdEfGh";
	//FILE* new_file = create_txt_file(file_name, contents);
	//read_file(file_name);
	//append_content(file_name, "123456");
	//printf("\n");
	//read_file(file_name);
	

	/* fscanf Test */
	char* file_name = "appending_test";
	char* contents = "Ab\nCd\nEf\nGh\n";
	FILE* new_file = create_txt_file(file_name, contents);
	read_file(file_name);
	printf("---------------------------");
	fscanf_test(file_name);

}
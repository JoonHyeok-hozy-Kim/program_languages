#include <stdio.h>
#include "string_header_test.h"
#include "human.h"
#include "preprocessor_test.h"

void main() {

	/* string.h library test. */
	//string_header_test();

	/* Header with struct test */
	//human_struct_test();

	/* Preprocessor Test */
	//preprocessor_define_test();
	ifdef_endif_test();

	return;
}
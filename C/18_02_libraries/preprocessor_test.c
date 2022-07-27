#include <stdio.h>
#define VAR1 10

void preprocessor_define_test() {

	char str[VAR1];
	int i;

	for (i = 0; i < VAR1 - 1; i++) {
		str[i] = i+65;
	}
	str[VAR1 - 1] = '\0';

	printf("%s", str);

}



#define AAA

int ifdef_endif_test() {
#ifdef AAA
	printf("AAA");
#endif
#ifdef BBB
	printf("BBB");
#endif
	return 0;
}


void memcpy_test() {

	char str[50] = "To be or not to be.";
	char str2[50];
	char str3[50];

	memcpy(str2, str, strlen(str) + 1); // 1 added for the NULL character at the end of the string.
	memcpy(str3, "hello", 6);

	printf("%s\n", str);
	printf("%s\n", str2);
	printf("%s\n", str3);
}


void memmove_test() {

	char str[50] = "To be or not to be.";

	printf("%s\n", str);
	printf("memmove!\n");
	memmove(str + 19, str + 13, 6);
	printf("%s\n", str);

}


void memcmp_test() {

	int arr[10] = { 1, 2, 3, 4, 5, 7 };
	int arr2[10] = { 1, 2, 3, 4, 5, 6 };

	if (memcmp(arr, arr2, 5) == 0) { // 5 Byte
		printf("Identical!\n");
	}
	else {
		printf("Different!\n");
	}

	if (memcmp(arr, arr2, 21) == 0) { // 21 Byte
		printf("Identical!\n");
	}
	else {
		printf("Different!\n");
	}
}
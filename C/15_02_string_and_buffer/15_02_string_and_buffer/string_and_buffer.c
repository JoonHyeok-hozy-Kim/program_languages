#include <stdio.h>
void main() {
	int a;
	char c;
	char s[10];

	/*
	printf("Give num : ");
	scanf("%d", &a);
	//printf("Give character : ");
	//scanf("%c", &c); // \n given after the previous input still remains in the buffer.
	printf("Give string : ");
	scanf("%s", &s); // \n given after the previous input still remains in the buffer.
	printf("Given num : (%d)\n", a);
	//printf("Given char : (%c)\n", c);
	printf("Given str : (%s)\n", s);
	*/


	// clearing buffer using fflush()
	/*printf("Give num : ");
	scanf("%d", &a);
	fflush(stdin);
	printf("Give character : ");
	scanf("%c", &c); 
	printf("Given num : (%d)\n", a);
	printf("Given char : (%c)\n", c);*/




	// clearing buffer using getchar()
	printf("Give num : ");
	scanf("%d", &a);
	getchar();
	printf("Give character : ");
	scanf("%c", &c); 
	printf("Given num : (%d)\n", a);
	printf("Given char : (%c)\n", c);

}
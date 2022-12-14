#include <stdio.h>

typedef struct {
    char * name;
    int age;
} person;


int main() {
    person *my_man1 = (person *) malloc(sizeof(person));
    my_man1->name = "hozy";
    my_man1->age = 30;

    
    person *my_man2 = malloc(sizeof(person));   // implicit typecasting
    my_man2->name = "aj";
    my_man2->age = 28;

    person *my_man3;
    my_man3 = (person *) malloc(sizeof(person));
    my_man3->name = "jh";
    my_man3->age = 31;


    printf("%s : %d\n", my_man1->name, my_man1->age);
    printf("%s : %d\n", my_man2->name, my_man2->age);
    printf("%s : %d\n", my_man3->name, my_man3->age);

    free(my_man1);
    free(my_man2);
    free(my_man3);
}
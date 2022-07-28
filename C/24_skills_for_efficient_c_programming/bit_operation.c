
/* 1) When storing multiple boolean like information  */
// Not desired.
struct Human {
	int is_alive;
	int is_walking;
	int is_running;
	int is_jumping;
	int is_sleeping;
	int is_eating;
};

// Desirable way of using bit operation.
#include <stdio.h>
#define ALIVE 0x1;
#define WALKING 0x2;
#define RUNNING 0x4;
#define JUMPING 0x8;
#define SLEEPING 0xC;
#define EATING 0x10;
void human_simulation() {
	//int my_status = ALIVE | WALKING | EATING;
	//if (my_status & ALIVE) {
	//	printf("I am ALIVE!! \n");
	//}
	//if (my_status & WALKING) {
	//	printf("I am WALKING!! \n");
	//}
	//if (my_status & RUNNING) {
	//	printf("I am RUNNING!! \n");
	//}
	//if (my_status & JUMPING) {
	//	printf("I am JUMPING!! \n");
	//}
	//if (my_status & SLEEPING) {
	//	printf("I am SLEEPING!! \n");
	//}
	//if (my_status & EATING) {
	//	printf("I am EATING!! \n");
	//}
	return;
}
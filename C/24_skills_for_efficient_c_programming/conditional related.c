#include "conditional_related.h"


// Binary Break Down
void binary_break_down_comparison() {

	int i, n = 100, remainder;
	int** arr[10];
	i = 0;
	// Ordinary if context.
	if (i == 1) {}
	else if (i == 2) {}
	else if (i == 3) {}
	else if (i == 4) {}
	else if (i == 5) {}
	else if (i == 6) {}
	else if (i == 7) {}
	else if (i == 8) {}


	// Binary Break Down
	if (i <= 4) {
		if (i <= 2) {
			if (i == 1) {}
			else {}
		}
		else {
			if(i==3){}
			else {}
		}
	}
	else {
		if (i <= 6) {
			if (i == 5) {}
			else {}
		}
		else {
			if (i==7) {}
			else {}
		}
	}

	
	// Switch Context
	switch (i) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	default:
		break;
	}


	// Use Look Up table if applicable
	char* table[] = { "EQ", "NE", "CS", "CC", "MI", "PL", "VS", "VC", "HI", "LS", "GE", "LT", "GT", "LE" };

}
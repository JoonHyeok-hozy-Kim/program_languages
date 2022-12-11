
/* 2) Avoid calling division operation as possible */

int inc_second_division(int second) { return (++second) % 60; }

int inc_second_condition(int second) {
	++second;
	if (second > 60) second %= 60;
	return second;
}

int divide_by_two_powers_r(int n, int r) { return n >> r; }
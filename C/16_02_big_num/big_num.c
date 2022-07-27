#include <stdio.h>
struct BigNum {
	int i_digit[100];	// Integer Part
	int d_digit[100];	// Decimal Part
	int i_total_digit;	// Integer Digit
	int d_total_digit;	// Decimal Digit
	int sign;			// 0 : Positive, 1 : Negative
};

int make_big_num(struct BigNum* big_num, char* num_str);
void copy_str(char* str1, char* str2, int digit);
void reverse(int* arr, int len);
void print_big_num(struct BigNum* big_num);

int addition(struct BigNum* num1, struct BigNum* num2, struct BigNum* num3);
int deduction(struct BigNum* num1, struct BigNum* num2, struct BigNum* num3);



void main() {
	struct BigNum num1, num2, num3;
	
	make_big_num(&num1, "-0123400.129");
	print_big_num(&num1);
	make_big_num(&num2, "0876666.4444400");
	print_big_num(&num2);

	//addition(&num1, &num2, &num3);
	//print_big_num(&num3);

	deduction(&num1, &num2, &num3);
	print_big_num(&num3);

}


int make_big_num(struct BigNum* big_num, char* num_str) {
	int i_flag = 1;
	int i_cnt = 0, d_cnt=0;
	int* i_temp_idx = &(big_num->i_digit);
	int* d_temp_idx = &(big_num->d_digit);
	int j;

	big_num->sign = 0;
	while (*num_str) {
		if (*num_str >= 48 && *num_str <= 57) {
			if (i_flag > 0) {
				//printf("pt_int %c\n", *num_str);
				if (i_cnt == 0 && *num_str == 48) {
					num_str++;
					continue;
				}
				*i_temp_idx = *num_str-48;
				i_temp_idx++;
				i_cnt++;
			}
			else {
				//printf("pt_d %c\n", *num_str);
				*d_temp_idx = *num_str - 48;
				d_temp_idx++;
				d_cnt++;
			}
		}
		else if (*num_str == '.') {
			i_flag *= -1;
			reverse(big_num->i_digit, i_cnt);
			big_num->i_total_digit = i_cnt;
		}
		else if (*num_str == '-') {
			big_num->sign = 1;
		}
		else {
			printf("Number format error!");
			return -1;
		}
		num_str++;
	}

	if (i_flag > 0) {
		reverse(big_num->i_digit, i_cnt);
		big_num->i_total_digit = i_cnt;
	}
	big_num->d_total_digit = d_cnt;

	return 0;
};

void copy_str(char* str1, char* str2, int digit) {
	int i;
	for (i = 0; i < digit; i++) {
		*str2 = *str1;
		str1++;
		str2++;
	}
	str2 = '\0';
};

void reverse(int* arr, int len) {
	int i;
	int temp;
	for (i=0; i<len/2; i++){
		temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
	}

};

void print_big_num(struct BigNum* big_num) {
	int i;
	if (big_num->sign == 1) {
		printf("-");
	}
	for (i = 0; i < (big_num->i_total_digit); i++) {
		printf("%d", (big_num->i_digit)[big_num->i_total_digit - 1 - i]);
	}
	printf(".");
	for (i = 0; i < (big_num->d_total_digit); i++) {
		printf("%d", (big_num->d_digit)[i]);
	}
	printf("\n");
};

int addition(struct BigNum* num1, struct BigNum* num2, struct BigNum* num3) {

	if (num1->sign == 1) {
		if (num2->sign == 1) {
			num3->sign = 1;
		}
		else {
			return deduction(num2, num1, num3);
		}
	}
	else {
		if (num2->sign == 1) {
			return deduction(num1, num2, num3);
		}
		else {
			num3->sign = 0;
		}
	}

	struct BigNum* max_i, *max_d, *min_i, *min_d;
	int j, temp, round_up=0;

	if (num1->i_total_digit > num2->i_total_digit) {
		max_i = num1;
		min_i = num2;
	}
	else {
		max_i = num2;
		min_i = num1;
	}
	num3->i_total_digit = max_i->i_total_digit;

	if (num1->d_total_digit > num2->d_total_digit) {
		max_d = num1;
		min_d = num2;
	}
	else {
		max_d = num2;
		min_d = num1;
	}
	num3->d_total_digit = max_d->d_total_digit;

	for (j = max_d->d_total_digit -1; j >= 0; j--) {
		if (min_d->d_total_digit -1 < j) {
			num3->d_digit[j] = max_d->d_digit[j];
			//printf("[pt1] %d\n", num3->d_digit[j]);
		}
		else {
			//printf("[pt2 at %d] %d + %d + %d\n", j, max_d->d_digit[j], min_d->d_digit[j], round_up);
			temp = max_d->d_digit[j] + min_d->d_digit[j] + round_up;
			round_up = temp / 10;
			temp %= 10;
			num3->d_digit[j] = temp;
			//printf("%d, %d\n", num3->d_digit[j], round_up);
		}
	}

	for (j = 0; j < max_i->i_total_digit; j++) {
		if (min_i->i_total_digit > j) {
			//printf("[i-pt1 at %d] %d + %d +%d\n", j, max_i->i_digit[j], min_i->i_digit[j], round_up);
			temp = max_i->i_digit[j] + min_i->i_digit[j] + round_up;
		}
		else {
			//printf("[i-pt2 at %d] %d + %d\n", j, max_i->i_digit[j], round_up);
			temp = max_i->i_digit[j] + round_up;
		}
		round_up = temp / 10;
		temp %= 10;
		num3->i_digit[j] = temp;
	}
	if (round_up > 0) {
		num3->i_total_digit++;
		num3->i_digit[max_i->i_total_digit] = round_up;
	}
};


int deduction(struct BigNum* num1, struct BigNum* num2, struct BigNum* num3) {
	if (num1->sign == 0 && num2->sign == 1) {
		num2->sign = 0;
		addition(num1, num2, num3);
	}
	else if (num1->sign == 1 && num2->sign == 0) {
		num2->sign = 1;
		addition(num1, num2, num3);
	}
	
	struct BigNum* max_i, * min_i, * max_d, * min_d;
	int j, temp, round_down=0;

	if (num1->i_total_digit > num2->i_total_digit) {
		max_i = num1;
		min_i = num2;
	}
	else {
		max_i = num2;
		min_i = num1;
	}

	if (num1->d_total_digit > num2->d_total_digit) {
		max_d = num1;
		min_d = num2;
	}
	else {
		max_d = num2;
		min_d = num1;
	}

	for (j = max_d->d_total_digit - 1; j >= 0; j--) {
		if (min_d->d_total_digit - 1 < j) {
			temp = 10 - max_d->d_digit[j] - round_down;
			round_down = 1;
			num3->d_digit[j] = temp;
		}
		else {
			min
		}
	}
	
	return 0;
};
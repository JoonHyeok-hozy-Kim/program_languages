int compare_str(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2) {
		return 0;
	}
	return 1;
}

void copy_str(char* dest, char* src) {
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

void fixed_length_string_display(char* str, int length) {
	int cnt = length;
	while (cnt > 0) {
		if (*str) {
			printf("%c", *str);
			str++;
		}
		else {
			printf(" ");
		}
		cnt--;
	}
}

int include_str(char* target, char* search_str) {
	int i, cnt = 0;
	while (*target) {
		if (*target == *search_str) {
			cnt++;
			target++;
			search_str++;
			if (*search_str) {
				continue;
			}
			else {
				return 1;
			}
		}
		else {
			for (i = 0; i < cnt; i++) {
				target--;
				search_str--;
			}
			target++;
			cnt = 0;
		}
	}
	return 0;
}
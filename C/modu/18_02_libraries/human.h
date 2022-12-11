enum {MALE, FEMALE};

struct Human {
	char name[20];
	int age;
	int gender;
};

struct Human create_human(char* name, int age, int gender);
void show_human_info(struct Human *human);

void human_struct_test();
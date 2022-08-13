

class MyString {
	char* string_content;
	int string_length;
	int capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString() { delete[] string_content; }
	int length() const { return string_length; }
	int show_capacity() const { return capacity; }
	void print() const;
	void println() const;
	void capacity_change(int new_capacity, int prev_capacity);
	void capacity_check(int target_capacity);
	MyString& assign(const char* str);
	MyString& assign(const MyString& str);
	char at(int i) const;

	MyString& insert(int loc, MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);

	int find(int start, const MyString& str) const;
	int find(int start, const char* str) const;
	int find(int start, char c) const;
	int find_brute_force(int start, const MyString& str) const;
	int find_kmp(int start, const MyString& str) const;
	int* _compute_kmp_fail(const MyString& str) const;

	int compare(const MyString& str) const;

	/* Chapter 5. Operator Overloading */
	bool operator==(MyString& str);

	/* 5-2. Subscript Operator Overloading */
	char& operator[](const int index);	// Check 05_02_operator_overloading_advanced.cpp
};

void mystring_instance_test();
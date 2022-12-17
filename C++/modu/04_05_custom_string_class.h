

class MyString {
	char* string_content;
	int string_length;
	int capacity;

public:
	MyString();
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	MyString(MyString&& str) noexcept;	// moving constructor (check "12_01_rvalue_reference.cpp")
	~MyString() { if(string_content) delete[] string_content; }	// condition added for moving constructor : Delete only when string content is not nullptr! 
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

	/* 12-1 */
	MyString operator+(const MyString& s);

	/* 12-2. move semantics */
	MyString operator=(const MyString& s);	// regular assignment operator
	MyString operator=(MyString&& s);		// move assignment operator
};

void mystring_instance_test();
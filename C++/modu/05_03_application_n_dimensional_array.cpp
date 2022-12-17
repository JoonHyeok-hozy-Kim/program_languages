#include "05_03_application_n_dimensional_array.h"
#include <iostream>

namespace MyArray {
	class Array;
	class Int;

class Array {
	friend Int;		// friend class and int Wrapper class

	const int dim;
	int* size;

	struct Address {
		int level;
		void* next;
	};

	Address* top;

public:
	Array(int dim, int* array_size);
	Array(const Array& arr);
	~Array();

	void initialize_address(Address* current);
	void delete_address(Address* current);
	void copy_address(Address* dest, Address* src);

	Int operator[](const int index);

};

Array::Array(int dim, int* array_size) : dim(dim) {
	size = new int[dim];
	for (int i = 0; i < dim; i++) size[i] = array_size[i];

	top = new Address;
	top->level = 0;

	initialize_address(top);
}

Array::Array(const Array& arr) : dim(arr.dim) {
	size = new int[dim];
	for (int i = 0; i < dim; i++) size[i] = arr.size[i];

	top = new Address;
	top->level = 0;

	initialize_address(top);
	copy_address(top, arr.top);
}

Array::~Array() {
	delete_address(top);
	delete[] size;
}

void Array::initialize_address(Address* current) {
	if (!current) return;	// Exception for the case when current is NULL.

	// Final stage of the recursion, when the level is equal to dim-1.
	if (current->level == dim - 1) {
		current->next = new int[size[current->level]];
		return;
	}

	// Else, assign Address* to its children.
	current->next = new Address[size[current->level]];
	for (int i = 0; i < size[current->level]; i++) {
		(static_cast<Address*>(current->next) + i)->level = current->level + 1;
		initialize_address(static_cast<Address*>(current->next) + i);
	}
}

void Array::delete_address(Address* current) {
	if (!current) return;

	if (current->level == dim - 1) {
		delete[] static_cast<int*>(current->next);
	}
	else {
		for (int i = 0; i < size[current->level]; i++) {
			delete_address(static_cast<Address*>(current->next) + i);
		}
		delete[] static_cast<Address*>(current->next);
	}
}

void Array::copy_address(Address* dst, Address* src) {
	if (dst->level == dim - 1) {
		for (int i = 0; i < size[dst->level]; i++) {
			static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
		}
		return;
	}

	for (int i = 0; i < size[dst->level]; i++) {
		Address* new_dst = static_cast<Address*>(dst->next) + i;
		Address* new_src = static_cast<Address*>(src->next) + i;

		copy_address(new_dst, new_src);
	}
}


class Int {
	void* data;
	int level;
	Array* array;

public:
	Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL)
		: level(_level), data(_data), array(_array) {

		// Exception for wrong data format
		if (_level < 1 || index >= array->size[_level - 1]) {
			data = NULL;
			return;
		}

		// integer assignment
		if (level == array->dim) {
			data = static_cast<void*>(static_cast<int*>(static_cast<Array::Address*>(data)->next) + index);
		}
		// Address assignment
		else {
			data = static_cast<void*>(static_cast<Array::Address*>(static_cast<Array::Address*>(data)->next) + index);
		}
	}

	Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

	// int Wrapper class : Int class will work like int* 
	operator int() {
		if (data) return *static_cast<int*>(data);
		else return 0;
	}

	// assignment operator overloading
	Int& operator=(const int& a) {
		std::cout << "in int::operator=, assign : " << a << std::endl;
		if (data) *static_cast<int*>(data) = a;
		
		return *this;
	}

	// subscript operator overloading for the access to the integer value!!!!
	Int operator[](const int index) {
		//std::cout << "in Int::operator[], index : " << index << std::endl;
		if (!data) return 0;
		return Int(index, level + 1, data, array);
	}

};

Int Array::operator[](const int index) {
	//std::cout << "in Array::operator[], index : " << index << std::endl;
	return Int(index, 1, static_cast<void*>(top), this);
}

} // namespace MyArray

void array_construction_test() {
	int num[2] = { 3, 4 };
	MyArray::Array arr(2, num);
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << "(" << i << "," << j << ") : " << i * 10 + j << std::endl;
			arr[i][j] = i*10 + j;
			std::cout << " assigned : " << arr[i][j] << std::endl;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
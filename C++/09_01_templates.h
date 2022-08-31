#include <iostream>
#include <string>

template <typename T>
class TemplateVector {
	T* data;
	int capacity;
	int length;

public:
	TemplateVector(int n = 1) : data(new T[n]), capacity(n), length(0) {};

	std::string str() {
		std::string s("[");
		for (int i = 0; i < length; i++) {
			//std::cout << typeid(data[i]).name() << " vs " << typeid(int).name() << std::endl;
			if (typeid(data[i]) == typeid(int)) {
				//std::cout << "case 1" << std::endl;
				//s += std::to_string(data[i]);	// needs treatment! hozy
			}
			else {
				//std::cout << "case 2" << std::endl;
				s += data[i];
			}

			if (i < length - 1) s += ", ";
		}
		s += "]";
		return s;
	}

	void print() {
		std::cout << str() << std::endl;
	}

	void capacity_change(double times){
		T* prev_data = data;
		capacity = (int)((double)capacity * times);
		//std::cout << "New capa : " << capacity << std::endl;
		if (capacity < length) {
			std::cout << "[Error] In Vector::capacity_change, capacity < length" << std::endl;
			return;
		}
		data = new T[capacity];
		for (int i = 0; i < length; i++) data[i] = prev_data[i];
		return;
	}

	void push_back(T s){
		if (capacity == length) capacity_change(2);
		data[length] = s;
		length++;
	}

	T operator[](int i) { return data[i]; }

	void remove(int x){
		if (length <= x) {
			std::cout << "[Error] In Vector::remove, length <= x" << std::endl;
			return;
		}
		if (x < length - 1) {
			for (int i = x; i < length - 1; i++) { data[i] = data[i + 1]; }
		}
		length--;
		if (length < capacity / 2) capacity_change(.5);
	}

	int size() { return length; }

	~TemplateVector() { delete[] data; }
};

void template_vector_test();
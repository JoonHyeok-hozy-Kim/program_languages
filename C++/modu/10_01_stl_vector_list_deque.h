#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> vec);
void stl_vector_test();

void range_based_for_loop_test();

#include <list>
template <typename T>
void print_list(std::list<T> list);
void stl_list_test();

#include <deque>
template <typename T>
void print_deque(std::deque<T> deque);
void stl_deque_test();
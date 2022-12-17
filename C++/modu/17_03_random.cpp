#include "17_03_random.h"


/* Tech.) How to create random numbers in C++ */

/* Sol 1) Pseudo Random Number <-- Not suggested! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
namespace PseudoRandomNumber {
	void test() {
		srand(time(NULL));		// Set seed using srand().

		for (int i = 0; i < 5; i++) {
			printf("Random Num : %d\n", rand() % 100);	// Use current second as random number!
		}
	}
}

void pseudo_random_number_test() {
	PseudoRandomNumber::test();
}


/* Sol 2) Use <random> module */
#include <iostream>
#include <random>
#include <iomanip>
#include <map>
namespace RandomModuleSimple {
	void uniform_distribution_test() {
		std::random_device rd;	// random_device to get a seed.

		std::mt19937 generator_obj(rd());	// Initialize a generator using Mersenne Twister based engine!

		std::uniform_int_distribution<int> dist_obj(0, 99);	// U~(0,99) distribution.

		for (int i = 0; i < 5; i++) {
			std::cout << "Random Number : " << dist_obj(generator_obj) << std::endl;
		}
	}

	void normal_distribution_test() {
		std::random_device rd;
		std::mt19937 gen(rd());

		std::normal_distribution<double> dist(0/*Mean*/, 1/*Variance*/);	// N~(0, 99) distribution
		
		std::map<int, int> hist{};
		for (int n = 0; n < 10000; ++n) {
			++hist[std::round(dist(gen))];
		}
		for (auto p : hist) {
			std::cout << std::setw(2) << p.first << ' '
				<< std::string(p.second / 100, '*') << " " << p.second << std::endl;
		}
	}
}

void random_uniform_distribution_test() {
	RandomModuleSimple::uniform_distribution_test();
}

void random_normal_distribution_test() {
	RandomModuleSimple::normal_distribution_test();
}


/* Tech.) How to utilize time in C++ : <chrono> module */

/* Example) Time Spent Calculation */
#include <chrono>
#include <vector>
namespace ChronoTest {

	namespace ch = std::chrono;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 100);

	void calculate_random_generator_time_spent() {
		for (int total = 1; total <= 1000000; total*=10) {
			std::vector<int> random_numbers;
			random_numbers.reserve(total);

			std::chrono::time_point<std::chrono::high_resolution_clock> start =
				std::chrono::high_resolution_clock::now();

			for (int i = 0; i < total; i++) {
				random_numbers.push_back(dist(gen));
			}

			std::chrono::time_point<std::chrono::high_resolution_clock> end =
				std::chrono::high_resolution_clock::now();

			// Before C++ 17, "auto time_diff = end - start;"
			// After C++ 17,
			std::chrono::duration time_diff = end - start;
			std::cout << "Creating " << std::setw(7) << total
				<< " random number(s) took time of : " << time_diff.count() << std::endl;
		}
	}


	void using_duration_cast() {
		for (int total = 1; total < 1000000; total*=10) {
			std::vector<int> random_numbers;
			random_numbers.reserve(total);

			ch::time_point<ch::high_resolution_clock> start = 
				ch::high_resolution_clock::now();

			for (int i = 0; i < total; i++) {
				random_numbers.push_back(dist(gen));
			}

			ch::time_point<ch::high_resolution_clock> end =
				ch::high_resolution_clock::now();

			ch::duration time_diff = end - start;
			std::cout << "Creating " << std::setw(7) << total
				<< " random number(s) took time of : " 
				<< ch::duration_cast<ch::microseconds>(time_diff).count() << "¥ìs"
				<< std::endl;
		}
	}
}

void chrono_random_generator_time_cnt() {
	ChronoTest::calculate_random_generator_time_spent();
}

void chrono_random_generator_time_cnt_duration_cast() {
	ChronoTest::using_duration_cast();
}


/* Tech.) Output for the time data with C++
	-> No module directly supports this.
		-> Use C functions...
*/

#include <ctime>
namespace TimeOutputTest {
	void simple_test() {
		auto now = std::chrono::system_clock::now();
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		std::cout << "Current Time : "
			<< std::put_time(std::localtime(&t), "%F %T %z") << std::endl;
	}
}


void time_output_simple_test() {
	TimeOutputTest::simple_test();
}
#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>

int main(int ac, char **av) {

	int value;
	if (ac != 2) {
		std::cout << "please enter a number to find" << std::endl;
		return 1;
	} else {
		std::istringstream iss(av[1]);
		if (!(iss >> value)) {
			std::cerr << "Invalid integer" << std::endl;
			return 1;
		}
	}
	
	const int min = -999;
	const int max = 999;
	std::srand(std::time(0));

	{
		std::cout << "Deque:" << std::endl;
		std::deque<int> bucket(999);
		std::deque<int>::iterator it;

		for (it = bucket.begin(); it != bucket.end(); ++it) {
			*it = min + std::rand() % (max - min + 1);
		}
		if (::easyfind(bucket, value)) 
			std::cout << "⭕ Occurence found" << std::endl;
		else
			std::cout << "❌ Occurence not found" << std::endl;
	}
	{
		std::cout << "List:" << std::endl;
		std::list<int> bucket(999);
		std::list<int>::iterator it;

		for (it = bucket.begin(); it != bucket.end(); ++it) {
			*it = min + std::rand() % (max - min + 1);
		}
		if (::easyfind(bucket, value)) 
			std::cout << "⭕ Occurence found" << std::endl;
		else
			std::cout << "❌ Occurence not found" << std::endl;
	}
	{
		std::cout << "Vector:" << std::endl;
		std::vector<int> bucket(999);
		std::vector<int>::iterator it;

		for (it = bucket.begin(); it != bucket.end(); ++it) {
			*it = min + std::rand() % (max - min + 1);
		}
		if (::easyfind(bucket, value)) 
			std::cout << "⭕ Occurence found" << std::endl;
		else
			std::cout << "❌ Occurence not found" << std::endl;
	}
	return 0;

}

#include "Span.hpp"



int main() {

	std::srand(std::time(0));
	Span nums(10);
	Span bucket(20);
	try {
		std::cout << "filling nums span with random int" << std::endl;
		nums.rfill(-534999, 456888);
		std::cout << "nums: " << nums << std::endl;
		std::cout << "assign nums with multiple int in one row: " << std::endl;
		nums.assign(5, 3);
		std::cout << "nums: " << nums << std::endl;
		std::cout << "filling bucket span with random int" << std::endl;
		bucket.rfill(-28, 199);
		std::cout << "bucket: " << bucket << std::endl;
		std::cout << "assign nums from bucket pointers: " << std::endl;
		nums.assign(bucket.begin(), bucket.end());
		std::cout << "nums: " << nums << std::endl;
		std::cout << "Shortest span is: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << nums.longestSpan() << std::endl;
		nums.addNumber(77); // should throw
	} catch (std::exception &e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}
	try {
		nums.assign(10, 99); 
		std::cout << nums << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		nums.assign(11, 99); 
		std::cout << nums << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		nums.assign(3, 33); 
		std::cout << nums << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	{
		std::cout << "Subject test: " << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}

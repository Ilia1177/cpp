#include "Span.hpp"
#include <ctime>
#include <cstdlib>

void	fillSpan(Span& s, int min, int max) {
	for (size_t i = s.index(); i < s.size(); ++i) {
		s.addNumber(min + std::rand() % (max - min + 1));
	}
}


int main() {

	std::srand(std::time(0));
	Span nums(10);
	Span bucket(20);
	try {
		std::cout << "filling nums..." << std::endl;
		fillSpan(nums, -534999, 456888);
		std::cout << "nums: " << nums << std::endl;
		std::cout << "assign nums from int: " << std::endl;
		nums.assign(5, 3);
		std::cout << "nums: " << nums << std::endl;
		std::cout << "filling bucket..." << std::endl;
		fillSpan(bucket, -28, 199);
		std::cout << "bucket: " << bucket << std::endl;
		std::cout << "assign nums from bucket pointers: " << std::endl;
		nums.assign(bucket.begin(), bucket.end());
		std::cout << "nums: " << nums << std::endl;
		std::cout << "Shortest span is: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << nums.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}
	{
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

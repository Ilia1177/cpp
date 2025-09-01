#include <vector>
#include "PmergeMe.hpp"

template <typename C>
bool is_sorted(C& arr) {
	if (arr.size() < 1)
		return true;
	typename C::iterator it;
	for (it = arr.begin() + 1; it < arr.end(); ++it) {
		if (*(it - 1) > *it) return false;
	}
	return true;
}

int main(int ac, char **av) 
{
	std::string query;
	PmergeMe<std::deque<elem_t> > 	deq;
	PmergeMe<std::vector<elem_t> > vec;
	std::string set;

	if (ac == 2) {
		set = av[1];
	} else {
		std::cerr << "Please enter an argument: a positive integer sequence" << std::endl;
		return 1;
	}
	try {
		std::cout << "before: "; deq.print(deq.read(set));
		double deqTime = deq.ford_johnson(set);
		std::cout << "after : "; deq.print(deq.getContainer());
		double vecTime = vec.ford_johnson(set);
		std::cout << "Time to process " << deq.getContainer().size() << " elements in a std::deque: " << deqTime << std::endl;
		std::cout << "Time to process " << deq.getContainer().size() << " elements in a std::vector: " << vecTime << std::endl;
		if (!is_sorted(vec.getContainer()) || !is_sorted(deq.getContainer()))
			throw std::logic_error("Container not sorted");
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	return 0;
}

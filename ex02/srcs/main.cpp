#include <vector>
#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
	std::string query;
	PmergeMe<std::deque<int> > 	deq;
	PmergeMe<std::vector<int> > vec;

	if (ac != 2)
		return 1;

	deq.read(av[1]);
	//deq.init_pair();
	deq.merge_insertion_sort(4);
}

#include <vector>
#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
	std::string query;
	PmergeMe<std::deque<elem_t> > 	deq;
	PmergeMe<std::vector<elem_t> > vec;

	(void)av;
	(void)ac;

	std::string set1 = "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7";
	std::string set2 = "30 49 60 1 31 29 42 46 13 8 5";
	deq.read(set2);
	//deq.init_pair();
	deq.merge_insertion_sort(1);
}

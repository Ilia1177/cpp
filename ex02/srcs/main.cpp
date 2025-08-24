#include <vector>
#include "PmergeMe.hpp"

template <typename C>
void ford_johnson_sort(C &arr, size_t elem_size /* start with 1 */);

int main(int ac, char **av) 
{
	std::string query;
	PmergeMe<std::deque<elem_t> > 	deq;
	PmergeMe<std::vector<elem_t> > vec;

	(void)av;
	(void)ac;

	std::string set1 = "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7";
	std::string set2 = "30 49 60 1 31 29 42 46 13 8 5";
	std::string set3 = " 999 30 87 54 99 49 60 8 888 5 0 6";
	deq.read(set1);
	
	deq.merge_insertion_sort(deq.getContainer());

	std::cout << deq.jacobsthal(1) << std::endl;
	std::cout << deq.jacobsthal(2) << std::endl;
	std::cout << deq.jacobsthal(3) << std::endl;
	std::cout << deq.jacobsthal(4) << std::endl;
	std::cout << deq.jacobsthal(5) << std::endl;
	std::cout << deq.jacobsthal(6) << std::endl;
	std::cout << deq.jacobsthal(7) << std::endl;
	std::cout << deq.jacobsthal(8) << std::endl;
	deq.print(deq.getContainer(), 0);
	std::cout << "comparison: " << __number_of_comp__ << std::endl;
//	ford_johnson_sort<std::deque<int> >(deq.getContainer(), 1);
//
//	for (std::deque<int>::iterator it = deq.getContainer().begin(); it < deq.getContainer().end(); ++it) {
//		std::cout << *it << ", ";
//	}

	//deq.init_pair();
	//deq.merge_insertion_sort(deq.getContainer(), 1);
}

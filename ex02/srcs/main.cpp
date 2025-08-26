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

template <typename C>
void sort_with(C& arr, const std::string& str)
{
		typedef typename C::container_type container_t;

		clock_t start = std::clock();
		arr.read(str);
		std::cout << "before: "; arr.print(arr.getContainer());
		arr.ford_johnson(arr.getContainer());
		std::cout << "after:  "; arr.print(arr.getContainer());
		clock_t end = std::clock(); double elapsed_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process " << arr.getContainer().size() << " elements in a ";
		if (is_vector<container_t>::value) std::cout << "std::vector is ";
		else if (is_deque<container_t>::value) std::cout << "std::deque is ";
		std::cout << elapsed_ms << " ms." << std::endl;;
}

int main(int ac, char **av) 
{
	std::string query;
	PmergeMe<std::deque<elem_t> > 	deq;
	PmergeMe<std::vector<elem_t> > vec;

	(void)av;
	std::string set1 = "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7";
//	std::string set2 = "30 49 60 1 31 29 42 46 13 8 5";
//	std::string set3 = " 999 30 87 54 99 49 60 8 888 5 0 6";
	if (ac == 2) {
		set1 = av[1];
	}
	try {
		sort_with(deq, set1);
		std::cout << "number of comparisons: " << __number_of_comp__ << std::endl;
		//sort_with(vec, av[1]);
		if (!is_sorted(deq.getContainer())) std::cout << "IS NOT SORTED !! WARNING !!" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>

template <typedef container>
class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

		int binarySearch(container arr, int x)
		{
			int high = arr.size() - 1;
			while (low <= high) {
				int mid = low + (high - low) / 2;

				// Check if x is present at mid
				if (arr[mid] == x)
					return mid;

				// If x greater, ignore left half
				if (arr[mid] < x)
					low = mid + 1;

				// If x is smaller, ignore right half
				else
					high = mid - 1;
			}
			// If we reach here, then element was not present
			return -1;
		}

	private:
		container input;
};

#endif


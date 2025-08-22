#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <stack>
# include <climits>
# include <cstdlib>
# include <stdexcept>
# include <exception>
# include <sstream>
# include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


int toInt(const std::string& str, char** endptr);

typedef struct elem_s {
	elem_s() {};
	elem_s(int val, std::string lab): value(val), label(lab) {};
	elem_s(int val): value(val), label("") {};
	elem_s(const elem_s& other): value(other.value), label(other.label) {};
	elem_s& operator=(const elem_s &other) {this->value = other.value; this->label = other.label; return *this;}
	bool operator<(elem_s &other) {return this->value < other.value;}
	int value;
	std::string label;
} elem_t;

template<typename C>
class PmergeMe
{
    public:
        PmergeMe(void) {};
        PmergeMe(const PmergeMe& other) {};
        PmergeMe &operator=(const PmergeMe &other) {};
        ~PmergeMe() {};

		void read(const std::string& input) {
			std::istringstream iss(input);
			int num;

			//iss.init(input);
			while (iss >> num) {
				_arr.push_back(elem_t(num));
			}

			//std::string str = input;
			//char *end;
			//while (str.length() > 0) {
			//	str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
			//	_arr.push_back(::toInt(str, &end));
			//	str = end;
			//}	
		}

		void print(C &c)
		{
			typename C::iterator it;
			typename C::iterator ite = c.end() - 1;

			for (it = c.begin(); it != c.end(); ++it) {
				if (it->label == "") {
					std::cout << it->value;
				} else if (it->label == "a") {
					std::cout << GREEN << it->value << RESET;
				} else if (it->label == "b") {
					std::cout << RED << it->value << RESET;
				}
				if (it != ite)
					std::cout << ", ";
			}
			std::cout << std::endl;
		}

		void print_pair(typename C::iterator it, size_t size) {
			for (; it != it + size && it < it + size; ++it) {
				std::cout << *it;
				if (it != it + size - 1)
					std::cout << ", ";
			}
			std::cout << std::endl;
		}

		typename C::iterator binarySearch(C& arr, int x, size_t size) {
			int low = size - 1;
			int high = arr.size() - 1;
			int mid;
			typename C::iterator best = arr.end(); // default = "not found"
			
			std::cout << "binary search: " << std::endl;
			if (arr.size() < size * 2)
				return arr.begin() + size - 1;
			while (low <= high) {
				mid = low + (((high + 1) - low) / (2 * size)) * size;

				std::cout << "mid: " << mid << " - low: " << low << " - high: " << high << std::endl;
				typename C::iterator it = arr.begin() + mid;

				if (it->value == x) {
					return it; // exact match
				} else if (it->value > x) {
					best = it;          // candidate: closest so far <= x
					high = mid - size;  // search left
				} else {
					low = mid + size;   // search right
				}
				//std::cout << "mid it: " << *it << std::endl;
				//std::cout << "best it: " << *best << std::endl;
			}
			return best; // may be arr.end() if all elements > x
		}

//		typename C::iterator binarySearch(C& arr, int x, size_t size) {
//			int low = size - 1;
//			int high = arr.size() - 1;
//
//			while (low <= high) {
//				int mid = low + (high - low) / 2;
//				typename C::iterator it = arr.begin() + mid;
//
//				if (*it == x)
//					return it;
//
//				if (*it < x)
//					low = mid + size;
//				else
//					high = mid - size;
//			}
//			return arr.end(); // not found
//		}
//
//		int binarySearch(int x) {
//
//    		int low = 0;
//			int high = _arr.size() - 1;
//			while (low <= high) {
//				int mid = low + (high - low) / 2;
//
//				// Check if x is present at mid
//				if (_arr[mid] == x)
//					return mid;
//
//				// If x greater, ignore left half
//				if (_arr[mid] < x)
//					low = mid + 1;
//
//				// If x is smaller, ignore right half
//				else
//					high = mid - 1;
//			}
//			// If we reach here, then element was not present
//			return -1;
//		}

		void swap(elem_t &a, elem_t &b) {
			elem_t tmp = a;
			a = b;
			b = tmp;
		}

		void swap_pair(typename C::iterator a, typename C::iterator b, size_t size) 
		{
			for (size_t i = 0; i < size; ++i) {
				swap(*(a + i), *(b + i));
			}
		}

		int jacobsthal(int k) {
		    return round((std::pow(2, k + 1) + std::pow(-1, k)) / 3);
		}

		void init_label(void) {
			typename C::iterator it = _arr.begin();
			for (; it < _arr.end(); ++it) {
					it->label = "";
				}
			}

		void assign_label(const size_t nb_pairs, const size_t elem_size)
		{
			typename C::iterator it = _arr.begin();
			for (; it < _arr.begin() + elem_size * (nb_pairs * 2); it += elem_size * 2) {
				for (size_t i = 0; i < elem_size; ++i) {
					(it + i)->label = "a";
				}
			}
			for (it = _arr.begin() + elem_size; it < _arr.begin() + elem_size * (nb_pairs * 2); it += elem_size * 2) {
				for (size_t i = 0; i < elem_size; ++i) {
					(it + i)->label = "b";
				}
			}
		}
		// sort elements inside of pairs by comparing them against each others: a <? b
		// element are describe by their last number inside it
		// for elem_size = 1 -> pair_size = 2;
		// [b1, a1], [b2, a2], [b3, a3] , .... 
		void sort_pairs(size_t elem_size)
		{
			typename C::iterator a, b;
			typename C::iterator start = _arr.begin();
			typename C::iterator end = _arr.end();
			const size_t pair_size = elem_size * 2;
	
			// Iterate on every pairs [b, a];
			// the 'a1' element is the second element, defined by its last number (if elem_size > 1)
			for (a = start + elem_size * 2 - 1; a < end; a += pair_size) {
				// define the 'b' element, as the element just before the current 'a' element
				b = a - elem_size;
				if (*a < *b)
					swap_pair(startOf(a, elem_size), startOf(b, elem_size), elem_size);
			}
		}

		typename C::iterator startOf(typename C::iterator it, size_t size) {
			return (it - size + 1);
		}

		void insert_in(C& arr, typename C::iterator it, size_t elem_size) {
			typename C::iterator idx;
			std::cout << "insert in: " << std::endl;
			idx = binarySearch(arr, it->value, elem_size);
			std::cout << "idx to insert from is: " << idx->value << std::endl;
			if (it->label == "")
				arr.insert(idx - (elem_size - 1), *it);
			else
				arr.insert(idx - (elem_size - 1), it - (elem_size - 1), it + 1);
		}

		void merge_insertion_sort(size_t elem_size)
		{
			size_t nb_pairs = _arr.size() / elem_size / 2;
			size_t nb_elems = nb_pairs * 2;
			//if (elem_size > _arr.size() / 2)
			if (nb_pairs < 1)
				return ;

			std::cout << "element size: " << elem_size << " - nb of elements: " << nb_elems << " - nb of pairs: " << nb_pairs << std::endl;

			init_label();
			std::cout << "Before: "; print(_arr);
			sort_pairs(elem_size);
			assign_label(nb_pairs, elem_size);
			std::cout << "Result: "; print(_arr);
			merge_insertion_sort(elem_size * 2);
			
			std::cout << "Part 2" << std::endl << std::endl;

			C pend, main;

			typename C::iterator it = _arr.begin();

			// push b1 element, (as this is the lowest element)
			for (; it < _arr.begin() + elem_size; ++it) {
				main.push_back(*it);
			}

			// push every 'a' elements into main 
			for (; it < _arr.begin() + elem_size * nb_elems; it += elem_size * 2) {
			//std::cout << "a elements from: " << *it << " to: " << *(_arr.begin() + elem_size * nb_elems) << std::endl;
			//std::cout << "push back to main: ";
				for (size_t i = 0; i < elem_size; ++i) {
					//if (i != elem_size - 1)
					//	std::cout << ", ";
					//else
					//	std::cout << std::endl;
					main.push_back(*(it + i));
				}
			}
			
			// push all other 'b' in pend
			for (it = _arr.begin() + elem_size * 2; it < _arr.begin() + elem_size * nb_elems; it += elem_size * 2) {
				for (size_t i = 0; i < elem_size; ++i) {
					pend.push_back(*(it + i));
				}
			}
			// push the remainder items (not paired items) in pend;
			for (it = _arr.begin() + elem_size * nb_elems; it < _arr.end(); ++it) {
				pend.push_back(*it);
			}

			std::cout << "size :" << elem_size << std::endl;
			std::cout << "main list: "; print(main);
			std::cout << "pend list: "; print(pend);

			//std::cout << *it << std::endl;
			while (!pend.empty()) {
				it = pend.begin();
				std::cout << "pend size: " << pend.size() << " - it to insert: " << it->value <<std::endl;;
				insert_in(main, it, elem_size);
				if (it->label == "")
					pend.erase(it);
				else
					pend.erase(it, it + elem_size);
				std::cout << "main list is: "; print(main);
			}
			std::cout << "reuslt main list: "; print(main);
		}

	private:
		C _arr;
};


#endif


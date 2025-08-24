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
static size_t __number_of_comp__ = 0;

typedef struct elem_s {
	elem_s() {};
	elem_s(int val, std::string lab): key(val), label(lab) {};
	elem_s(int val): key(val), label("") {};
	elem_s(const elem_s& other): key(other.key), label(other.label) {};
	elem_s& operator=(const elem_s &other) {this->key = other.key; this->label = other.label; return *this;}
	bool operator<(const elem_s &other) const {__number_of_comp__++; return this->key < other.key;}
	bool operator==(const elem_s &other) const {__number_of_comp__++; return this->key == other.key;}
	bool operator<(const int val) const {__number_of_comp__++; return this->key < val;}
	bool operator>(const elem_s &other) const {__number_of_comp__++; return this->key > other.key;}
	bool operator>(const int val) const {__number_of_comp__++; return this->key > val;}
	int key;
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

		typedef typename C::iterator Citer;

		C& getContainer(void) {return _arr;}; 

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

		void print(C &c, size_t size)
		{
			typename C::iterator it;
			typename C::iterator ite = c.end() - 1;
			size_t i = 0;
			size_t pair_size = size * 2;
			size_t curr_pair = 1;
			size_t nb_pairs;
			if (size)
				nb_pairs = c.size() / size / 2;
			else
				nb_pairs = 0;

			for (it = c.begin(); it != c.end(); ++it) {

				if (pair_size && i == 0 && curr_pair <= nb_pairs)
					std::cout << "[";
				if (it->label == "") {
					std::cout << it->key;
				} else if (it->label[0] == 'a') {
					std::cout << GREEN << it->key << RESET;
				} else if (it->label[0] == 'b') {
					std::cout << RED << it->key << RESET;
				}
				if (pair_size == ++i) {
					++curr_pair;
					std::cout << "]";
					i = 0;
				}


				if (it != ite)
					std::cout << ", ";
			}
			std::cout << std::endl;
		}

// Binary search function that returns the insertion position
typename C::iterator binarySearch(typename C::iterator begin, typename C::iterator end, const int value) {
    typename C::iterator low = begin;
    typename C::iterator high = end;
    
    while (low < high) {
		std::cout << "binary search" << std::endl;
        typename C::iterator mid = low + (low - high) / 2;
		if (mid->key == value) {
			return mid;
		} else if (mid->key < value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}
		Citer binarySearch6(C& arr, Citer start, Citer end, Citer it)
		{
			Citer best = arr.end(); // default = "not found"

			if (arr.size() < 1)
				return best;

			int low = 0;
			int high = arr.size() - 1;
			int mid;

			while (low <= high) {
				mid = low + (high  - low) / 2;

				//std::cout << "mid: " << mid << " - low: " << low << " - high: " << high << std::endl;
				Citer half = arr.begin() + mid;

				if (*half == *it) {
					return half; // exact match
				} else if (*half > *it) {
					best = half;          // candidate: closest so far <= x
					high = mid - 1;  // search left
				} else {
					low = mid + 1;   // search right
				}
				//std::cout << "mid it: " << *it << std::endl;
				//std::cout << "best it: " << *best << std::endl;
			}
			return best; // may be arr.end() if all elements > x
		}

		Citer binarySearch(C& arr, Citer start, Citer end, Citer it)
		{
			Citer best = end; // default = "not found"

			if (arr.size() < 1)
				return best;

			Citer low = start;
			Citer high = end;
			Citer mid;

			while (low <= high) {
				mid = low + (high  - low) / 2;

				//std::cout << "mid: " << mid << " - low: " << low << " - high: " << high << std::endl;
				//Citer half = arr.begin() + mid;

				if (*mid == *it) {
					return mid; // exact match
				} else if (*mid > *it) {
					best = mid;          // candidate: closest so far <= x
					high = mid - 1;  // search left
				} else {
					low = mid + 1;   // search right
				}
				//std::cout << "mid it: " << *it << std::endl;
				//std::cout << "best it: " << *best << std::endl;
			}
			return best; // may be arr.end() if all elements > x
		}

		void swap(elem_t &a, elem_t &b) {
			elem_t tmp = a;
			a = b;
			b = tmp;
		}

		size_t jacobsthal(size_t k) {
			if (k == 0 || k == 1) return k;
			size_t a = 0, b = 1, c;
			for (size_t i = 2; i <= k; ++i) {
				c = b + 2 * a;
				a = b;
				b = c;
			}
			return b;
		}

		void init_label(C& arr, std::string label) {
			size_t nb_pairs = arr.size() / 2;
			typename C::iterator it = arr.begin();
			std::ostringstream oss;
			size_t curr_pair = 1;
			for (; it < arr.begin() + nb_pairs * 2; ++it) {
					oss << label << curr_pair;
					it->label = oss.str();
					curr_pair++;
				}
		}

		void assign_label(C& arr, const size_t nb_pairs, const size_t elem_size)
		{
			size_t curr_pair = 1;
			std::ostringstream oss_b, oss_a;
			typename C::iterator it = arr.begin();

			for (; it < arr.begin() + elem_size * (nb_pairs * 2); it += elem_size * 2) {
				oss_b << "b" << curr_pair;
				oss_a << "a" << curr_pair;
				size_t i = 0;
				for (; i < elem_size; ++i) {
					(it + i)->label = oss_b.str();
				}
				for (; i < elem_size * 2; ++i) {
					(it + i)->label = oss_a.str();
				}
				curr_pair++;
			}
		}

		// sort elements inside of pairs by comparing them against each others: a <? b
		// element are describe by their last number inside it
		// for elem_size = 1 -> pair_size = 2;
		// [b1, a1], [b2, a2], [b3, a3] , .... 
		void sort_pairs(C& arr)
		{
			Citer a, b;
			Citer start = arr.begin();
			Citer end = arr.end();
	
			// Iterate on every pairs [b, a];
			// the 'a1' element is the second element, defined by its last number (if elem_size > 1)
			for (a = start + 1; a < end; a += 2) {
				// define the 'b' element, as the element just before the current 'a' element
				b = a - 1;
				if (*a < *b) swap(*a, *b);
			}
		}

	void split_leaders(C& arr, C& main, C& pend)
	{
		size_t nb_pairs = arr.size() / 2;

		Citer start = arr.begin();
		Citer ite = arr.begin() + nb_pairs * 2;

		// push all leaders 'a' elements into mains 
		for (Citer it = start + 1; it < ite; it += 2) {
			main.push_back(*it);
		}
		// push all 'b' blocks into pend
		for (Citer it = arr.begin(); it < ite; it += 2) {
			pend.push_back(*it);
		}
		// push leftovers into pend
		for (typename C::iterator it = ite ; it < arr.end(); ++it) {
			pend.push_back(*it);
		}
	}

	void insert(C& main, C& pend) 
	{
		// push 'b1' into main without comparison (as we know it is smaller than a1)
		main.push_front(*(pend.begin()));

		std::cout << "push b1:           === main: "; print(main, 0);
		std::cout << "                       pend: "; print(pend, 0);

		size_t curr_idx;
		size_t k = 3;
		size_t inserted = 1;

		Citer end;

		while (inserted < pend.size()) {
			size_t to_insert = jacobsthal(k) - jacobsthal(k-1);
			curr_idx = std::min(jacobsthal(k), pend.size()) - 1;
			size_t stop = curr_idx + 1;
			end = main.begin() + stop;
			while (to_insert > 0 && inserted < pend.size()) {
				std::cout << "index to insert: " << curr_idx << " nb to insert: " << to_insert << std::endl;
				Citer it = pend.begin() + curr_idx;
				Citer pos = binarySearch(main, main.begin(), main.end(), it);


				std::cout << "pos: " << it->key << " at: " << pos->key << " end: " << end->key << "   === main: "; print(main, 0);
				if (std::distance(pos, end) == 1)
					stop--;

				--stop;
				end = main.begin() + stop;
				main.insert(pos, *it);

				--curr_idx;
				
				--to_insert;
				++inserted;
				std::cout << "                          pend: "; print(pend, 0);
			}
			++k;
		}
		return ;
	}

	void merge_insertion_sort(C& arr)
	{
		size_t nb_pairs = arr.size() / 2;

		if (nb_pairs < 1) return;

		//init_label(arr, "");
		std::cout << " === FORD JOHNSON  === ";
		std::cout << "Input : "; print(arr, 0); 
		std::cout << " === SORTING PAIRS === ";
		sort_pairs(arr);
		assign_label(arr, nb_pairs, 1);
		std::cout << "Result: "; print(arr, 0);


		std::cout << " === SPLIT LEADERS === ";
		C main, pend;
		split_leaders(arr, main, pend);
		//init_label(main, "a");
		//init_label(pend, "b");
		std::cout << "Main is "; print(main, 0);
		std::cout << "                       Pend is "; print(pend, 0);

		// recursivly sort leaders
		merge_insertion_sort(main);
		std::cout << " === RECURSIV CALL " << " = "; std::cout << "new main: "; print(main, 0);
		std::cout << " ===   INSERTING   === "; std::cout << "Pend is "; print(pend, 0);

		insert(main, pend);


		//typename C::iterator it_a = main.begin();
		//typename C::iterator it_b = pend.begin();
	//	typename C::iterator pos;
	//	typename C::iterator idx;

	//	size_t k = 3;
	//	size_t inserted = 1; // b1 already placed

	//	while (inserted < pend.size()) {
	//		size_t idx = jacobsthal(k) - jacobsthal(k - 1);
	//		std::cout << idx << std::endl;
	//		for (size_t m = 0; m < idx && inserted < pend.size(); ++m) {
	//			typename C::iterator it = pend.begin();
	//			std::advance(it, inserted);
	//			typename C::iterator pos = binarySearch(main, it->key, 1);
	//			main.insert(pos, *it);
	//			++inserted;
	//		}
	//		++k;
	//	}

//		typename C::iterator it = pend.begin();
		
//		for (; it < pend.end(); ++it) {
//			typename C::iterator pos = binarySearch( main, it->key, 1);
//			main.insert(pos, *it);
//		}

		std::cout << "                       Result: "; print(main, 0);

		// Step 5: write back
		std::cout << " --- END ---" << std::endl;
		arr.swap(main);
	}

	private:
		C _arr;
};


#endif


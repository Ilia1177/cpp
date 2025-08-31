#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
#include <iterator>
# include <stack>
# include <climits>
# include <cstdlib>
# include <stdexcept>
# include <exception>
# include <sstream>
# include <cmath>
# include <iomanip>
# include <ctime>
# include <vector>
# include <deque>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


int toInt(const std::string& str, char** endptr);
extern size_t __number_of_comp__;
// Base false case
template <typename T>
struct is_vector { static const bool value = false; };

// Specialization for std::vector
template <typename T, typename Alloc>
struct is_vector<std::vector<T, Alloc> > { static const bool value = true; };

// Base false case
template <typename T>
struct is_deque { static const bool value = false; };

// Specialization for std::deque
template <typename T, typename Alloc>
struct is_deque<std::deque<T, Alloc> > { static const bool value = true; };

typedef struct elem_s {
	elem_s() {};
	elem_s(int val, std::string lab): key(val), label(lab), pairIndex(-1) {};
	elem_s(int val): key(val), label(""), pairIndex(-1) {};
	elem_s(const elem_s& other): key(other.key), label(other.label), pairIndex(other.pairIndex) {};
	elem_s& operator=(const elem_s &other) {if (this != &other) {this->key = other.key; this->label = other.label; this->pairIndex = other.pairIndex;} return *this;}
	bool operator<(const elem_s &other) const {__number_of_comp__++; return this->key < other.key;}
	bool operator==(const elem_s &other) const {__number_of_comp__++; return this->key == other.key;}
	bool operator<(const int val) const {__number_of_comp__++; return this->key < val;}
	bool operator>(const elem_s &other) const {__number_of_comp__++; return this->key > other.key;}
	bool operator>(const int val) const {__number_of_comp__++; return this->key > val;}
	int key;
	std::string label;
	int pairIndex;
	int prev_pairIndex;
} elem_t;

template<typename C>
class PmergeMe
{
    public:
        PmergeMe(void) {};
        PmergeMe(const PmergeMe& other) {};
        PmergeMe &operator=(const PmergeMe &other) {};
        ~PmergeMe() {};

		typedef C container_type;   // <-- this is what your sort_with expects
		typedef typename C::iterator Citer;

		C& getContainer(void) {return _arr;}; 

		void read(const std::string& input)
		{
			std::string str = input;
			char *end;
			while (str.length() > 0) {
				str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
				_arr.push_back(elem_t(::toInt(str, &end)));
				str = end;
				str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
			}	
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
					   nb_pairs = c.size() / (size * 2);
			   else
					   nb_pairs = 0;

			   for (it = c.begin(); it != c.end(); ++it) {

					   if (pair_size && i == 0 && curr_pair <= nb_pairs)
							   std::cout << "[";
					   if (it->label == "") {
							   std::cout << it->key;
					   } else if (it->label == "a") {
							   std::cout << GREEN << it->key << RESET;
					   } else if (it->label == "b") {
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

		void print(C &c, C &pend, size_t size)
		{
			typename C::iterator it;
			typename C::iterator ite = c.end() - 1;

			(void)pend;
			size_t i = 0;
			for (it = c.begin(); it != c.end(); ++it) {

				
				if (it->label == "") {
					std::cout << std::setw(2) << it->key << ":" << it->pairIndex; 
				} else if (it->label[0] == 'a') {
					std::cout << GREEN << std::setw(2) << it->key << ":" << it->pairIndex << RESET;

				} else if (it->label[0] == 'b') {
					std::cout << RED << std::setw(2) << it->key << ":"  << it->pairIndex << RESET;

				}
				if (it != ite)
					std::cout << ", ";
				i++;
				if (i > size) i = 0;
			}
			std::cout << std::endl;
		}
		void print(C &c)
		{
			typename C::iterator it;
			typename C::iterator ite = c.end() - 1;

			for (it = c.begin(); it != c.end(); ++it) {

				if (it->label == "") {
					std::cout << std::setw(2) << it->key; //<< "(" << it->pairIndex << ")" ;
				} else if (it->label[0] == 'a') {
					std::cout << GREEN << std::setw(2) << it->key << RESET;// << "(" << it->pairIndex << ")" << RESET;
				} else if (it->label[0] == 'b') {
					std::cout << RED << std::setw(2) << it->key << RESET;// << "(" << it->pairIndex << ")" << RESET;
				}
				if (it != ite)
					std::cout << ", ";
			}
			std::cout << std::endl;
		}

		Citer binarySearch(C& arr, size_t start, size_t end, Citer it)
		{
			if (start >= end) return arr.begin() + end;
			
			size_t low = start;
			size_t high = end;
			
			while (low < high) {
				size_t mid = low + (high - low) / 2; 
				
				// Only ONE element comparison per iteration
				if (*(arr.begin() + mid) > *it) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			return arr.begin() + low;
		}

		void swap(elem_t &a, elem_t &b) {
			elem_t tmp = a;
			a = b;
			b = tmp;
		}

		size_t jacobsthal(size_t k) const {
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
			//size_t nb_pairs = arr.size() / 2;
			typename C::iterator it = arr.begin();
			//std::ostringstream oss;
			//size_t curr_pair = 1;
			for (; it < arr.end(); ++it) {
					//oss << label << curr_pair;
					it->label = label;
					//curr_pair++;
				}
		}

		void assign_label(C& arr, const size_t elem_size)
		{
			size_t nb_pairs = arr.size() / (elem_size * 2);
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

		void sort_pairs(C& arr, size_t size)
		{
			Citer a, b;
			Citer start = arr.begin();
			size_t nb_pairs = arr.size() / (size * 2);
			Citer end = arr.begin() + size * nb_pairs * 2;
	
			// Iterate on every pairs [b, a];
			// the 'a1' element is the second element, defined by its last number (if elem_size > 1)
			for (a = start + size; a < end; a += size * 2) {
				// define the 'b' element, as the element just before the current 'a' element
				b = a - size;
				if (*(a + size - 1) < *(b + size - 1)) {
					for (size_t i = 0; i < size; ++i) {
						swap(*(a + i), *(b + i));
					}
				}
			}
		}

	void split_leaders(C& arr, C& main, C& pend, size_t size)
	{
		size_t nb_pairs = arr.size() / (size * 2);

		Citer start = arr.begin();
		Citer ite = arr.begin() + nb_pairs * 2 * size;

		// push all leaders 'a' elements into mains 
		for (Citer it = start + size; it < ite; it += 2 * size) {
			main.insert(main.end(), it, it + size);
		}
		// push all 'b' blocks into pend
		for (Citer it = arr.begin(); it < ite; it += 2 * size) {
			pend.insert(pend.end(), it, it + size);
		}
		// push leftovers into pend
		for (typename C::iterator it = ite ; it < arr.end(); ++it) {
			pend.push_back(*it);
		}
	}

	void update_pair_index(C& main, C& pend, size_t prev_index, size_t size) {

		size_t i;

		Citer a = main.begin() + prev_index * size;
		std::cout << "update pair index, start at " << a->key << ", previous index: " << prev_index << ", size: " << size << std::endl;
		for (i = 0; i < size; ++i) {
			(a + i)->pairIndex = 0;
		}
		prev_index++;
		Citer b = pend.begin();
		// iterate throught main using a->pairIndex to reach b element in pend to update theirs pairs indexes
		for (i = prev_index * size; i < main.size(); i += size) {
			a = main.begin() + i;
			int b_index = a->pairIndex;
				for (size_t j = 0; j < size; ++j) {
					b = pend.begin() + b_index * size + j;
					b->pairIndex++;
					//if ((size_t)b->pairIndex > main.size() / size)
					//	throw std::logic_error("index is TOO HIGH");
				}
		}

		Citer unpaired = pend.begin() + a->pairIndex * size + size;
		for (; unpaired < pend.end(); ++unpaired) {
			unpaired->pairIndex++;
			if ((size_t)unpaired->pairIndex > main.size() / size) {

				std::cout << "at index: "<< std::distance(pend.begin(), unpaired) % size << " of a total size of " << pend.size() / size << std::endl;
				throw std::logic_error("index is TOO HIGH - caught in end of pend");
				
			}
		}
	}
	
	void print_index(C& arr) {
		for (Citer it = arr.begin(); it < arr.end(); ++it) {
			std::cout << it->key << ":" << it->pairIndex << ", ";
		}
		std::cout << std::endl;
	}

	void assign_pair_index(C& main, C& pend, size_t size) {
		std::cout << "Init index - size: " << size << std::endl;
		size_t i = 0;
		int index = 0;
		Citer a = main.begin();
		Citer b = pend.begin();
		for (; a < main.end(); a += size) {
			for (i = 0; i < size; ++i) {
				(a + i)->pairIndex = index;
				(b + i)->pairIndex = index;
				//std::cout << (b+i)->key << "->" << (b+i)->pairIndex << std::endl;
			}
			index++;
			b += size;
		}
		for (; b < pend.end(); ++b) {
			b->pairIndex = main.size() / size;
		}
	}
		// binary search takes index of block of elements
		Citer binarySearch(C& arr, size_t start, size_t end, Citer it, size_t size)
		{
			std::cout << "Binary search - start: " << start << " end: " << end << " it: " << it->key << " key: " << (it + size -1)->key << std::endl;
			if (start >= end) return arr.end();
			
			size_t low = start;
			size_t high = end ;
			
			while (low < high) {
				size_t mid = (low + high) / 2;
				
				if (*(arr.begin() + mid * size + size - 1) > *(it + size - 1)) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			return arr.begin() + low * size;
		}

	void binary_insertion(C& main, C& pend, size_t size) 
	{
	
		init_label(main, "a");
		init_label(pend, "b");
		assign_pair_index(main, pend, size);
		//print_index(pend);
		// push 'b1' into main without comparison (as we know it is smaller than a1)
		std::cout << "-- inserting b1" << std::endl;
		main.insert(main.begin(), pend.begin(), pend.begin() + size);
		std::cout << "-- update pend index" << std::endl;
		update_pair_index(main, pend, 0, size);
		print_index(pend);
		size_t nb_of_elements = pend.size() / size;

		Citer pos;
		size_t curr_idx;
		size_t k = 3;		 	// 3
		size_t inserted = size;	// 1

		while (inserted < pend.size()) {
			size_t to_insert = jacobsthal(k) - jacobsthal(k-1);
			curr_idx = std::min(jacobsthal(k) * size, (nb_of_elements) * size) - size ;  // - size ??
			while (to_insert > 0 && inserted < pend.size()) {
				if (pend.size() - inserted < size) {
					main.insert(main.end(), pend.begin() + inserted, pend.end());
					std::cout  << "inserted: " << inserted << "PUSH all remainders" << std::endl << std::endl;
					return ;
				}

				//std::cout << "start (main): "; print(main);
				//std::cout << "start (pend): "; print(pend);

				//print_index(pend);

				Citer b = pend.begin() + curr_idx;

				std::cout << "current index: " << curr_idx << " of b to insert: " << b->key << " binary search from: 0 to: " << b->pairIndex  << std::endl;

				// Search for position to insert in main current b element, from 0 to its pair index
				//if (b->pairIndex >= 0) {
				if ((size_t)b->pairIndex > main.size() / size) {
					std::cout << RED << "index max of main: " << main.size() / size << std::endl;
					std::cout << "while inserting: " << b->key << " to " << (b+size -1)->key; 
					std::cout << "index: " << b->pairIndex << RESET << std::endl; 
					throw std::logic_error("index out of range");
				}
				pos = binarySearch(main, 0, b->pairIndex, b, size);
				//} else {
				//	pos = binarySearch(main, 0, main.size() / size, b, size);
				//}
				
				size_t index = std::distance(main.begin(), pos);

				std::cout << "inserting at index: " << index / size << std::endl;
				//std::cout << "pend index before insertion: " ; print_index(pend);

				main.insert(pos, b, b + size);
				update_pair_index(main, pend, index / size, size);

				//std::cout << "pend index after update    : "; print_index(pend);
				//std::cout << "result (main): ";print(main);
				//std::cout << "result (pend):" ;print(pend);

				for (Citer it = main.begin() + size; it < main.end(); it += size) {
					if ((it + size -1 )->key < (it - 1)->key) {
						std::cout << RED << "while inserting: " << b->key << " to " << (b+size -1)->key 
							<< " of index: " << b->pairIndex 
							<< " in index: " << index / size << std::endl;
						std::cout << (it - 1)->key << " !< " << (it + size -1)->key << RESET << std::endl;
						throw std::logic_error("not sorted");
					}
				}
				inserted += size;
				curr_idx -= size;
				to_insert--;
			}
			++k;
		}
		return ;
	}



	void merge_insertion(C& arr, size_t size)
	{
		size_t nb_pairs = arr.size() / (size * 2);
		//bool is_odd = arr.size() % 2;
		static size_t recursiv =  0;
		if (nb_pairs < 1) return;

		init_label(arr, "");
		std::cout << " === FORD JOHNSON === " << ++recursiv ;
		assign_label(arr, size);
		std::cout << std::setw(8) << " Input: "; print(arr); 

		// main is sorting -- mirror is broken
		sort_pairs(arr, size);
		std::cout << " === SORTING PAIRS === ";
		std::cout << std::setw(8) << "main: "; print(arr);

		merge_insertion(arr, size * 2);
		// split array into main & pend; // arr remain unchanged
		C main, pend;
	  	split_leaders(arr, main, pend, size);

		std::cout << " === SPLIT LEADERS === " << recursiv << " main: "; print(main);
		std::cout << "                         pend: "; print(pend);

		std::cout << " === ASSIGN INDEX size: " << size << " main: "; print(main);
		assign_pair_index(main, pend, size);

		print_index(main);
		print_index(pend);
		std::cout << " === RECURSIV CALL == " << recursiv << "  main: "; print(main);
		std::cout << " ===   INSERTING   ===   pend: "; print(pend);

		binary_insertion(main, pend, size);

		std::cout << " ===    END        ===   main: "; print(main);
		arr.swap(main);
	}

	void assign_index(C& main, C* pend) {
		if (pend && !pend->empty()) {
			size_t i = 0;
			Citer ita = main.begin();
			Citer itb = pend->begin();
			for (;ita < main.end(); ita++) {
				ita->pairIndex = i;
				itb->pairIndex = i;
				i++;
			}
		}
	}

	void ford_johnson(C &arr)
	{
		//sort_pairs(arr, NULL);
		merge_insertion(arr, 1);
	}

	private:
		C _arr;
};


#endif


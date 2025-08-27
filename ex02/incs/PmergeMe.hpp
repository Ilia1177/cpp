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

		void print(C *c)
		{
			if (!c) {
				std::cout << std::endl;
				return;
			}
			typename C::iterator it;
			typename C::iterator ite = c->end() - 1;

			for (it = c->begin(); it != c->end(); ++it) {

				if (it->label == "") {
					std::cout << std::setw(2) << it->key << ":" << it->pairIndex;
				} else if (it->label[0] == 'a') {
					std::cout << GREEN << std::setw(2) << it->key << ":" << it->pairIndex ;
				} else if (it->label[0] == 'b') {
					std::cout << RED << std::setw(2) << it->key;//  << "(" << it->pairIndex << ")" << RESET;
				}
				if (it != ite)
					std::cout << ", ";
			}
			std::cout << std::endl;
		}

		void print(C &c, C *pend)
		{
			typename C::iterator it;
			typename C::iterator ite = c.end() - 1;

			for (it = c.begin(); it != c.end(); ++it) {

				if (it->label == "") {
					std::cout << std::setw(2) << it->key << ":" << (pend->begin() + it->pairIndex)->key;
				} else if (it->label[0] == 'a') {
					std::cout << GREEN << std::setw(2) << it->key << ":" << (pend->begin() + it->pairIndex)->key;
				} else if (it->label[0] == 'b') {
					std::cout << RED << std::setw(2) << it->key << ":" << (pend->begin() + it->pairIndex)->key;
				}
				if (it != ite)
					std::cout << ", ";
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
					std::cout << GREEN << std::setw(2) << it->key;// << "(" << it->pairIndex << ")" << RESET;
				} else if (it->label[0] == 'b') {
					std::cout << RED << std::setw(2) << it->key ;// << "(" << it->pairIndex << ")" << RESET;
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

		Citer binarySearch(C& arr, size_t start, size_t end, Citer it, size_t size)
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
					low = mid + size;
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

		void sort_pairs(C& arr, C* pend)
		{
			Citer a, b;
			Citer start = arr.begin();
			Citer end = arr.end();
	
			size_t pend_a = 1;
			size_t pend_b = 0;
			// Iterate on every pairs [b, a];
			// the 'a1' element is the second element, defined by its last number (if elem_size > 1)
			for (a = start + 1; a < end; a += 2) {
				// define the 'b' element, as the element just before the current 'a' element
				b = a - 1;
				if (*a < *b) {
					if (pend && !pend->empty()) {
						(pend->begin() + pend_a)->pairIndex++;
						(pend->begin() + pend_b)->pairIndex--;
						swap(*(pend->begin() + pend_a), *(pend->begin() + pend_b));
					}
					a->pairIndex++;
					b->pairIndex--;
					swap(*a, *b);
				}
				pend_a+=2;
				pend_b+=2;
			}
		}

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

		void sort_pairs_bySize(C& arr, size_t size)
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

	void reassign_pair_index(C& arr, size_t inserted_index)
	{
		Citer it;

		if (inserted_index <= 0)
			inserted_index++;
		for (it = arr.begin() + inserted_index /* - 1 */; it < arr.end(); ++it) {
			it->pairIndex++;
		}
	}

	void assign_pair_index(C& arr) {
		Citer it;

		size_t index = 0;
		for (it = arr.begin(); it < arr.end(); ++it) {
			it->pairIndex = ++index;
		}
	//	size_t index = 1;
	//	for (it = arr.begin() + 1; it < arr.end(); ++it) {
	//		it->pairIndex = ++index;
	//	}
	}

	void binary_insertion(C& main, C& pend, size_t size) 
	{
		// push 'b1' into main without comparison (as we know it is smaller than a1)
		main.insert(main.begin(), pend.begin(), pend.begin() + size);

		assign_pair_index(pend);
	//	size_t nb_pairs = main.size() / size;
		std::cout << " key | pos | end | === main:   "; print(main);

		size_t curr_idx;
		size_t k = 3;		 	// 3
		size_t inserted = 1;	// 1

		while (inserted < pend.size()) {
			size_t to_insert = jacobsthal(k) - jacobsthal(k-1);
			curr_idx = std::min(jacobsthal(k), pend.size()) - 1;
			//if (curr_index < nb_pairs * size)
			//	curr_idx *= size;
			while (to_insert > 0 && inserted < pend.size()) {
				Citer it = pend.begin() + curr_idx;

			//	std::cout << "comparisons: " << __number_of_comp__ << std::endl;
				Citer pos = binarySearch(main, 0, /*it->pairIndex*/ main.size(), it);
				std::cout 
					<< std::setw(4) << it->key 
					<< std::setw(6) << pos->key 
					<< std::setw(6) << (main.begin() + it->pairIndex)->key << "(index: " << it->pairIndex << ")"
					<< "  ---> main:   "; print(main);

				reassign_pair_index(pend, std::distance(main.begin(), pos));
			//	if (paired > 0) {
			//		main.insert(pos, it, it + size);
			//		inserted += size;
			//	} else {
					main.insert(pos, *it);
					inserted++;
			//	}


				--curr_idx;
				--to_insert;
				//std::cout << "                          pend: "; print(pend, 0);
			}
			++k;
		}
		return ;
	}

	void binary_insertion(C& main, C& pend) 
	{
		// push 'b1' into main without comparison (as we know it is smaller than a1)
		std::cout << "insert b1 index: " << main.begin()->pairIndex << " === main:   "; print(main);
		main.insert(main.begin(), *(pend.begin()) /*+ (main.begin()->pairIndex))*/);

		assign_pair_index(pend);
		
		std::cout << " key | pos | end | === main:   "; print(main);

		size_t curr_idx;
		size_t k = 3;		 	// 3 -- 1
		size_t inserted = 1;	// 1 -- 0

		while (inserted < pend.size()) {
			size_t to_insert = jacobsthal(k) - jacobsthal(k-1);
			curr_idx = std::min(jacobsthal(k), pend.size()) - 1;
			while (to_insert > 0 && inserted < pend.size()) {
				Citer it = pend.begin() + curr_idx;

			//	std::cout << "comparisons: " << __number_of_comp__ << std::endl;
				Citer pos = binarySearch(main, 0, /*it->pairIndex*/ main.size(), it);
				std::cout 
					<< std::setw(4) << it->key 
					<< std::setw(6) << pos->key 
					<< std::setw(6) << (main.begin() + it->pairIndex)->key << "(index: " << it->pairIndex << ")"
					<< "  ---> main:   "; print(main);

				reassign_pair_index(pend, std::distance(main.begin(), pos));
				main.insert(pos, *it);

				--curr_idx;
				--to_insert;
				++inserted;
				//std::cout << "                          pend: "; print(pend, 0);
			}
			++k;
		}
		return ;
	}

	void ford_johnson(C& arr, size_t size)
	{
	//	std::cout << "comparisons: " << __number_of_comp__ << std::endl;
		size_t nb_pairs = arr.size() / (size * 2);

		if (nb_pairs < 1) return;

		init_label(arr, "");
		std::cout << " === FORD JOHNSON  " << size << " = input : "; print(arr, size); 

		sort_pairs(arr, size);

		assign_label(arr,  size);
		std::cout << " === SORTING PAIRS === ";
		std::cout << "Result: "; print(arr, size);

		ford_johnson(arr, size * 2);
		C main, pend;
	  	split_leaders(arr, main, pend, size);
		std::cout << " === SPLIT LEADERS === main:   "; print(main, size);
		std::cout << "                       Pend:   "; print(pend, size);

	  // recursivly sort leaders
		std::cout << " === RECURSIV CALL === main:   "; print(main);
		std::cout << " ===   INSERTING   === pend:   "; print(pend);

		binary_insertion(main, pend, size);

		std::cout << " ===    END        === main:   "; print(main);
		arr.swap(main);
	}


	void merge_insertion(C& arr) {
		size_t nb_pairs = arr.size() / 2;


		if (nb_pairs < 1) return;

		std::cout << " === FORD JOHNSON === ";
		std::cout << "Input: "; print(arr); 

		// main is sorting -- mirror is broken
		sort_pairs(arr);
		std::cout << " === SORTING PAIRS === ";
		std::cout << "main: "; print(arr);
		//std::cout << std::setw(29) << "pend: "; print(pend);

		//sort_pairs(arr);
		//std::cout << " === SORT ARRAY   === arr :"; print(arr);

	//	size_t i = 0;
	//	Citer it;
	//	for (it = arr.begin(); it < arr.begin() + nb_pairs * 2 - 1; it += 2) {
	//		it->pairIndex = i; (it + 1)->pairIndex = i++;
	//	}
	//	for (; it < arr.end(); ++it) it->pairIndex = -1;

		// split array into main & pend; // arr remain unchanged
		C main, pend;
	  	split_leaders(arr, main, pend);
		std::cout << " === SPLIT LEADERS === main:   "; print(main);
		std::cout << "                       pend:   "; print(pend);



		merge_insertion(main);


		std::cout << " === RECURSIV CALL === main:   "; print(main);
		std::cout << " ===   INSERTING   === pend:   "; print(pend);

		binary_insertion(main, pend);
	//	binary_insertion(arr, order);

		std::cout << " ===    END        === main:   "; print(main);
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

	int* save_index(C& lead, C* rems, std::vector<int> , std::vector<int> remsidx) {
		Citer itl = lead.begin();
		Citer itr = rems.begin();


	}


void merge_insertion(C& main, C* pend) {
		size_t nb_pairs = main.size() / 2;


		if (nb_pairs < 1) return;

		std::cout << " === FORD JOHNSON === ";
		std::cout << "Input : "; print(main); 
		if (pend) {std::cout << std::setw(29) << "pend : "; print(pend); }

		sort_pairs(main, pend);
		std::cout << " === SORTING PAIRS === ";
		std::cout << "main: "; print(main);
		std::cout << std::setw(29) << "pend: "; print(pend);
		//sort_pairs(arr);
		//std::cout << " === SORT ARRAY   === arr :"; print(arr);
 
		C leaders, rems;
	  	split_leaders(main, leaders, rems);

		// assign the new pair index to both leaders and rems
		assign_index(leaders, &rems);
		std::cout << " === ASSIGN  INDEX === main: "; print(leaders, &rems);

		std::cout << " === SPLIT LEADERS === lead: "; print(leaders);
		std::cout << "                       rems: "; print(rems);
		
		// save_index(old_index); of rems
		// 
		int *old_index;

		merge_insertion(leaders, &rems);

		
		std::cout << " === RECURSIV CALL === lead: "; print(leaders);
		std::cout << " ===   INSERTING   === rems: "; print(rems);
		
		for (Citer it = leaders.begin() ; it < leaders.end() ; ++it) {
			std::cout << "a: " << it->key << " -> b: " << (rems.begin() + it->pairIndex)->key << std::endl;
		}
		
		binary_insertion(leaders, rems);
	//	binary_insertion(arr, order);

		std::cout << " ===    END        === main: "; print(main);
		main.swap(leaders);
	}


	void ford_johnson(C &arr)
	{
		//sort_pairs(arr, NULL);
		merge_insertion(arr);
	}

	private:
		C _arr;
};


#endif


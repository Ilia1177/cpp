#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <cerrno> // Required for errno and ERANGE
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>
//
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int toInt(const std::string& str, char** endptr);

extern size_t g_comparison;

// Base false case
template <typename T> struct is_vector {
    static const bool value = false;
};

// Specialization for std::vector
template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc> > {
    static const bool value = true;
};

// Base false case
template <typename T> struct is_deque {
    static const bool value = false;
};

// Specialization for std::deque
template <typename T, typename Alloc> struct is_deque<std::deque<T, Alloc> > {
    static const bool value = true;
};

typedef struct elem_s {
    elem_s();
    elem_s(int val, std::string lab);
    elem_s(int val);
    elem_s(const elem_s& other);
    ~elem_s();
    elem_s&     operator=(const elem_s& other);
    bool        operator<(const elem_s& other) const;
    bool        operator==(const elem_s& other) const;
    bool        operator<(const int val) const;
    bool        operator>(const elem_s& other) const;
    bool        operator>(const int val) const;
    int         key;
    std::string label;
    int         pairIndex;
} elem_t;

template <typename C> class PmergeMe
{
  public:
    PmergeMe(void) {}
    PmergeMe(const PmergeMe& other) : _arr(other._arr) {}
    PmergeMe& operator=(const PmergeMe& other)
    {
        if (this != &other) {
            this->_arr = other._arr;
        }
        return *this;
    }
    ~PmergeMe() {}

    typedef C                    container_type;
    typedef typename C::iterator Citer;

    C&     read(const std::string& input);
    void   print(C& c, size_t size);
    void   print(C& c);
    void   swap(elem_t& a, elem_t& b);
    size_t jacobsthal(size_t k) const;
    void   init_label(C& arr, std::string label, size_t size);
    void   assign_label(C& arr, const size_t elem_size);
    void   sort_pairs(C& arr, size_t size);
    void   split_leaders(C& arr, C& main, C& pend, size_t size);
    void   update_pair_index(C& main, C& pend, size_t inserted_index, size_t size);
    void   assign_pair_index(C& main, C& pend, size_t size);
    Citer  binarySearch(C& arr, Citer it, size_t size);
    void   binary_insertion(C& main, C& pend, size_t size);
    void   merge_insertion(C& arr, size_t size);
    double ford_johnson(const std::string& str);
    C&     getContainer(void);
    bool   is_sorted(C& arr);

  private:
    C _arr;
};

/////////////////////////// PARSING AND UTILS ///////////////////////////////
template <typename C> 
C& PmergeMe<C>::getContainer(void) { return _arr; };

template <typename C> 
C& PmergeMe<C>::read(const std::string& input)
{
    _arr.clear();
    std::string str = input;
    char*       end;
    while (str.length() > 0) {
        str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
		_arr.push_back(elem_t(::toInt(str, &end)));
        str = end;
        str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
    }
    return _arr;
}

template <typename C>
void PmergeMe<C>::print(C& c, size_t size)
{
    Citer  it;
    Citer  ite = c.end() - 1;
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

template <typename C>
void PmergeMe<C>::print(C& c)
{
    Citer it;
    Citer ite = c.end() - 1;

    for (it = c.begin(); it != c.end(); ++it) {
        if (it->label == "") {
            std::cout << std::setw(2) << it->key;
        } else if (it->label[0] == 'a') {
            std::cout << GREEN << std::setw(2) << it->key << RESET;
        } else if (it->label[0] == 'b') {
            std::cout << RED << std::setw(2) << it->key << RESET;
        }
        if (it != ite)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

template <typename C>
void PmergeMe<C>::init_label(C& arr, std::string label, size_t size)
{
    Citer it = arr.begin();
    for (size_t i = 0; i < size; ++i) {
        (it + i)->label = label;
    }
}

template <typename C> void PmergeMe<C>::assign_label(C& arr, const size_t elem_size)
{
    size_t             nb_pairs = arr.size() / (elem_size * 2);
    size_t             curr_pair = 1;
    std::ostringstream oss_b, oss_a;
    Citer              it = arr.begin();

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

/////////////////////////// LOGIC EXECUTION /////////////////////////////////

template <typename C> void PmergeMe<C>::swap(elem_t& a, elem_t& b)
{
    elem_t tmp = a;
    a = b;
    b = tmp;
}

template <typename C> size_t PmergeMe<C>::jacobsthal(size_t k) const
{
    if (k == 0 || k == 1)
        return k;
    size_t a = 0, b = 1, c;
    for (size_t i = 2; i <= k; ++i) {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

// sort elements inside of pairs by comparing them against each others: a <? b
// element are described by their last number inside it
// for elem_size = 1 -> pair_size = 2;
// [b1, a1], [b2, a2], [b3, a3] , ....
template <typename C> void PmergeMe<C>::sort_pairs(C& arr, size_t size)
{
    Citer  a, b;
    Citer  start = arr.begin();
    size_t nb_pairs = arr.size() / (size * 2);
    Citer  end = arr.begin() + size * nb_pairs * 2;

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

template <typename C> void PmergeMe<C>::split_leaders(C& arr, C& main, C& pend, size_t size)
{
    size_t nb_pairs = arr.size() / (size * 2);

    Citer start = arr.begin();
    Citer ite = arr.begin() + nb_pairs * 2 * size;
    Citer it;
    // push all leaders 'a' elements into mains
    for (it = start + size; it < ite; it += 2 * size) {
        main.insert(main.end(), it, it + size);
    }
    // push all 'b' blocks into pend
    for (it = start; it < ite; it += 2 * size) {
        pend.insert(pend.end(), it, it + size);
    }
    // push leftovers into pend
    for (it = ite; it < arr.end(); ++it) {
        pend.push_back(*it);
    }
}

// the index 0 (referencing b0) is given to the newly inserted element.
// b0 is gonna be incremented more than main.size() but we ll never use its index
// b0 is never gonna be inserted throught binarySearch since it has already been inserted first
template <typename C>
void PmergeMe<C>::update_pair_index(C& main, C& pend, size_t inserted_index, size_t size)
{
    size_t i;

    // give the newly inserted element the pair index = 0
    Citer a = main.begin() + inserted_index++;
    for (i = 0; i < size; ++i) {
        (a + i)->pairIndex = 0;
    }

    // iterate throught main using a->pairIndex to reach b element in pend to update theirs pairs
    // indexes
    Citer b = pend.begin();
    for (i = inserted_index; i < main.size(); i += size) {
        a = main.begin() + i;
        int b_index = a->pairIndex;
        for (size_t j = 0; j < size; ++j) {
            b = pend.begin() + b_index * size + j;
            b->pairIndex++;
        }
    }

    // Get to b(n/2) from a(n/2) wich are the last element in main to get to the last unpaired
    // elements of pend
    Citer unpaired = pend.begin() + a->pairIndex * size + size;
    for (; unpaired < pend.end(); ++unpaired) {
        unpaired->pairIndex++;
    }
}

template <typename C> void PmergeMe<C>::assign_pair_index(C& main, C& pend, size_t size)
{
    size_t i = 0;
    int    index = 0;
    Citer  a = main.begin();
    Citer  b = pend.begin();
    for (; a < main.end(); a += size) {
        for (i = 0; i < size; ++i) {
            (a + i)->pairIndex = index;
            (b + i)->pairIndex = index;
        }
        index++;
        b += size;
    }
    for (; b < pend.end(); ++b) {
        b->pairIndex = main.size() / size;
    }
}

// binary search takes index of block of elements
template <typename C>
typename PmergeMe<C>::Citer PmergeMe<C>::binarySearch(C& arr, Citer it, size_t size)
{
    size_t low = 0;
    size_t high = it->pairIndex;

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

template <typename C> void PmergeMe<C>::binary_insertion(C& main, C& pend, size_t size)
{
    size_t nb_of_elements = pend.size() / size;
    size_t k = 3;
    size_t inserted = size;

    // init pair indexes of both pend & main
    assign_pair_index(main, pend, size);
    // push 'b1' into main without comparison (as we know b1 is smaller than a1)
    main.insert(main.begin(), pend.begin(), pend.begin() + size);
    update_pair_index(main, pend, 0, size);

    while (inserted < pend.size()) {
        // get the amount of blocks to insert
        size_t blocks_to_insert = jacobsthal(k) - jacobsthal(k - 1);
        size_t curr_idx = std::min(jacobsthal(k) * size, nb_of_elements * size) - size;
        while (blocks_to_insert > 0 && inserted < pend.size()) {
            // Push unpaired elements at the end of main
            if (pend.size() - inserted < size) {
                main.insert(main.end(), pend.begin() + inserted, pend.end());
                return;
            }
            Citer b = pend.begin() + curr_idx;
            Citer pos = binarySearch(main, b, size);

            size_t previous_index = std::distance(main.begin(), pos);

            main.insert(pos, b, b + size);
            update_pair_index(main, pend, previous_index, size);

            inserted += size;
            curr_idx -= size;
            blocks_to_insert--;
        }
        ++k;
    }
    return;
}

template <typename C> void PmergeMe<C>::merge_insertion(C& arr, size_t size)
{
    size_t nb_pairs = arr.size() / (size * 2);
    if (nb_pairs < 1)
        return;

#if DETAILS
    // Start of Ford Johnson, labelling for colored output
    init_label(arr, "", arr.size());
    std::cout << " === FORD JOHNSON  === size: " << size << std::endl;
    std::cout << std::setw(23) << "└─>  arr: ";
    print(arr, size);
#endif

    sort_pairs(arr, size);

#if DETAILS
    std::cout << " === SORTING PAIRS === size: " << size << std::endl;
    std::cout << std::setw(23) << "└─>  arr: ";
    assign_label(arr, size);
    print(arr, size);
#endif

    // Recursively sort pairs, increasing the size of the pairs
    merge_insertion(arr, size * 2);

    // init_label(arr, "", arr.size());
    //  split array into main & pend; // arr remain unchanged
    C main, pend;
    split_leaders(arr, main, pend, size);

#if DETAILS
    init_label(main, "a", main.size());
    init_label(pend, "b", main.size());
    std::cout << " === SPLIT LEADERS === size: " << size << std::endl;
    std::cout << std::setw(23) << "└─>  arr: ";
    print(arr);
    std::cout << std::setw(23) << "└─> main: ";
    print(main);
    std::cout << " ===   INSERTING   === size: " << size << std::endl;
    std::cout << std::setw(23) << "└─> pend: ";
    print(pend);
#endif

    binary_insertion(main, pend, size);

#if DETAILS
    std::cout << " ===    END        === " << std::endl;
    std::cout << std::setw(23) << "└─> main: ";
    print(main);
#endif

    arr.swap(main);
}

template <typename C> double PmergeMe<C>::ford_johnson(const std::string& str)
{
    g_comparison = 0;
    clock_t start = std::clock();
    merge_insertion(read(str), 1);
    clock_t end = std::clock();

#if DETAILS
    std::cout << "number of comparisons: " << g_comparison << std::endl;
#endif

    double ms_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    return ms_time;
}

#endif

// Ford–Johnson (merge-insertion) for random-access containers (C++98)
#include <vector>
#include <deque>
#include <algorithm>  // swap, lower_bound (unused here), iter_swap
#include <iterator>   // distance

// -------------------- utilities --------------------

template <typename C>
static void swap_blocks(typename C::iterator a, typename C::iterator b, size_t s) {
    for (size_t i = 0; i < s; ++i) std::iter_swap(a + i, b + i);
}

// Ensure in every adjacent pair of blocks [i..i+s-1] and [i+s..i+2s-1],
// the block with the larger tail (last element) is on the RIGHT.
template <typename C>
static void sort_pairs_by_tail(C &arr, size_t s) {
    if (s == 0) return;
    const size_t n = arr.size();
    for (size_t i = 0; i + 2*s <= n; i += 2*s) {
        if (arr[i + s - 1] > arr[i + 2*s - 1]) {
            swap_blocks<C>(arr.begin() + i, arr.begin() + i + s, s);
        }
    }
}

// Split into MAIN (right blocks) and PEND (left blocks). Handle leftovers.
template <typename C>
static void split_main_pend(const C &arr, size_t s, C &mainOut, C &pendOut) {
    const size_t n = arr.size();
    mainOut.clear(); pendOut.clear();

    // Full pairs of blocks
    size_t i = 0;
    for (; i + 2*s <= n; i += 2*s) {
        // After sort_pairs_by_tail, right block has the larger tail
        // main = right block, pend = left block
        mainOut.insert(mainOut.end(), arr.begin() + i + s, arr.begin() + i + 2*s);
        pendOut.insert(pendOut.end(), arr.begin() + i,     arr.begin() + i + s);
    }

    // Leftover: could be < s or between s and < 2s
    size_t rem = n - i;
    if (rem >= s) {
        // One extra left block without partner: goes to pend
        pendOut.insert(pendOut.end(), arr.begin() + i, arr.begin() + i + s);
        i += s; rem -= s;
    }
    if (rem > 0) {
        // Tail shorter than s (final leftovers): also pend
        pendOut.insert(pendOut.end(), arr.begin() + i, arr.end());
    }
}

// Build Jacobsthal insertion order (block indices, 0-based).
// Insert blocks in groups: for J_k, insert indices (J_k-1 .. J_{k-1}) in descending order.
// We stop once we cover m blocks.
static std::vector<size_t> jacobsthal_order(size_t m) {
    std::vector<size_t> J; // Jacobsthal numbers >= 1
    // Generate J1=1, J2=1, then Jn=Jn-1 + 2*Jn-2
    J.push_back(1);
    J.push_back(1);
    while (J.back() < m) {
        size_t sz = J.size();
        J.push_back(J[sz-1] + 2*J[sz-2]);
    }

    std::vector<size_t> order;
    order.reserve(m);
    size_t prev = 0;
    for (size_t k = 0; k < J.size() && prev < m; ++k) {
        size_t hi = J[k];
        if (hi > m) hi = m;
        // push (hi-1 .. prev) descending
        size_t idx = hi;
        while (idx > prev) {
            order.push_back(idx - 1); // zero-based block index
            --idx;
        }
        prev = hi;
    }
    return order; // length == m
}

// Binary search among *block boundaries* in MAIN using the block's tail as key.
// Returns iterator position in MAIN where the block [first,last] should be inserted.
template <typename C>
static typename C::iterator lower_bound_block_by_tail(C &mainArr,
                                                      const typename C::value_type &keyTail,
                                                      size_t s)
{
    // Search only at indices ... s-1, 2*s-1, 3*s-1, ...
    if (mainArr.empty()) return mainArr.begin();

    // low/high are indices to *tails* of blocks
    long low  = (long)s - 1;
    long high = (long)mainArr.size() - 1;

    // Guard: if the very first block tail is >= key, insert at block begin
    if (!(mainArr[low] < keyTail)) return mainArr.begin();

    // If key is greater than the last block tail, insert at end
    if (mainArr[high] < keyTail) return mainArr.end();

    while (low <= high) {
        long midTail = low + ((high - low) / (2*s)) * (long)s; // snap to a tail
        if (midTail < 0) midTail = 0; // safety (shouldn't happen if s>0)

        if (mainArr[midTail] < keyTail) {
            low = midTail + (long)s;
        } else {
            high = midTail - (long)s;
        }
    }
    // 'low' is the first tail >= keyTail; insertion point is the BEGIN of that block
    return mainArr.begin() + (low - ((long)s - 1));
}

// Insert a *whole block* (of size s) from PEND into MAIN using the block's tail as key.
template <typename C>
static void insert_block_by_tail(C &mainArr,
                                 const C &pendArr,
                                 size_t blockIndex, // 0-based
                                 size_t s)
{
    const size_t first = blockIndex * s;
    const size_t last  = first + s; // [first, last)
    typename C::value_type keyTail = pendArr[last - 1];

    typename C::iterator pos = lower_bound_block_by_tail<C>(mainArr, keyTail, s);
    mainArr.insert(pos, pendArr.begin() + first, pendArr.begin() + last);
}

// Insert any leftover (< s) elements one by one (plain lower_bound on elements).
template <typename C>
static void insert_tail_elements(C &mainArr, const C &tail) {
    for (typename C::const_iterator it = tail.begin(); it != tail.end(); ++it) {
        // classic lower_bound on elements
        typename C::iterator pos = std::lower_bound(mainArr.begin(), mainArr.end(), *it);
        mainArr.insert(pos, *it);
    }
}

// -------------------- main recursive routine --------------------

template <typename C>
void ford_johnson_sort(C &arr, size_t elem_size /* start with 1 */) {
    const size_t n = arr.size();
    if (elem_size == 0 || elem_size >= n) return;

    // 1) Inside each adjacent pair of blocks, ensure larger tail is on the right
    sort_pairs_by_tail<C>(arr, elem_size);

    // 2) Split into MAIN (right blocks) and PEND (left blocks, plus leftovers)
    C mainArr, pendArr;
    split_main_pend<C>(arr, elem_size, mainArr, pendArr);

    // 3) Recursively sort MAIN at the next block size
    ford_johnson_sort<C>(mainArr, elem_size * 2);

    // 4) Insert full PEND blocks in Jacobsthal order
    const size_t fullBlocks = pendArr.size() / elem_size;
    const size_t rem        = pendArr.size() % elem_size;

    std::vector<size_t> order = jacobsthal_order(fullBlocks);
    for (size_t k = 0; k < order.size(); ++k) {
        insert_block_by_tail<C>(mainArr, pendArr, order[k], elem_size);
    }

    // 5) Leftover < elem_size elements: insert one-by-one
    if (rem) {
        C tail;
        tail.insert(tail.end(),
                    pendArr.begin() + fullBlocks * elem_size,
                    pendArr.end());
        insert_tail_elements<C>(mainArr, tail);
    }

    // 6) Write result back
    arr.swap(mainArr);
}

template void ford_johnson_sort<std::deque<int> >(std::deque<int>&, size_t);

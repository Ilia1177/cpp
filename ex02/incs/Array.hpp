#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array
{
    public:
        Array(void);
		Array(const size_t size);
        Array(const Array& other);
        Array &operator=(const Array &other);
        ~Array();

		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		size_t	size() const;
	private:
		size_t	_size;
		T*		_tab;
};
//template<typename T>
//T& Array<T>::operator[](size_t index);
//
template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array);

# include "Array.tpp"
#endif


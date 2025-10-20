#pragma once

template<typename T>
bool easyfind(T& container, int toFind) {

    typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), toFind);
    return  (it != container.end());
}


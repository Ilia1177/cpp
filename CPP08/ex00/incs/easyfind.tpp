#pragma once


template<typename T>
bool easyfind(T& container, int toFind) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (*it == toFind) return true;
    }
    return false;
}

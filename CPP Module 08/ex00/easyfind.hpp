#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int easyfind(T& container, int value) {
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter != container.end()) {
        std::cout << "Found " << value << " in container" << std::endl;
        return *iter;
    } else {
        throw std::out_of_range("Could not find value");
    }
}




#endif
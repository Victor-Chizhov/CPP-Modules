#include "iter.hpp"

template <typename T> void iter(T *arr, size_t len, void (*func)(T&)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T, typename U> void iter(const T *arr, const size_t len, U &func) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T> void print(T &elem) {
    std::cout << elem << std::endl;
}
#include "iter.hpp"

template <typename T> void iter(T *arr, size_t len, void (*func)(T&)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T, typename U> void iter(T *arr, size_t len, void (*func)(U&)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T> void print(T &elem) {
    std::cout << elem << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print);
    return 0;
}
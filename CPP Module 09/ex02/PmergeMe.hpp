#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

void insertionSortVector(std::vector<int> &arr);
void mergeSortVector(std::vector<int> &arr, int left, int mid, int right);
void mergeInsertSortVector(std::vector<int> &arr);
void mergeInsertSortDeque(std::deque<int> &arr);

template <typename T>
void push(size_t value, T &arr) {
    arr.push_back(value);
}

template <typename T>
void print(T &arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

#endif
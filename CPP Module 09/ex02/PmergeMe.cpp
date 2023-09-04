#include "PmergeMe.hpp"

void mergeInsertSortVector(std::vector<int> &arr) {
    if (arr.size() <= 1)
        return;

    std::vector<int> left;
    std::vector<int> right;

    for (size_t i = 0; i < arr.size() / 2; i++) {
        left.push_back(arr[i]);
    }
    for (size_t i = arr.size() / 2; i < arr.size(); i++) {
        right.push_back(arr[i]);
    }
    mergeInsertSortVector(left);
    mergeInsertSortVector(right);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeInsertSortDeque(std::deque<int> &arr) {
    if (arr.size() <= 1)
        return;

    std::deque<int> left;
    std::deque<int> right;

    for (size_t i = 0; i < arr.size() / 2; i++) {
        left.push_back(arr[i]);
    }
    for (size_t i = arr.size() / 2; i < arr.size(); i++) {
        right.push_back(arr[i]);
    }
    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
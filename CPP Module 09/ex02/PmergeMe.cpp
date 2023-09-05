#include "PmergeMe.hpp"

void insertionSortVector(std::vector<int> &arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeInsertSortVector(std::vector<int> &arr) {
    if (arr.size() <= 1)
        return;

    if (arr.size() <= 20) {
        insertionSortVector(arr);
    } else {
        std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
        std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());

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
}

void insertionSortDeque(std::deque<int> &arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeInsertSortDeque(std::deque<int> &arr) {
    if (arr.size() <= 1)
        return;

    if (arr.size() <= 20) {
        insertionSortDeque(arr);
    } else {
        std::deque<int> left(arr.begin(), arr.begin() + arr.size() / 2);
        std::deque<int> right(arr.begin() + arr.size() / 2, arr.end());

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
}
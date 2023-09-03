#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &other) {
    *this = other;
}
PmergeMe::~PmergeMe() {}
PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
    if (this != &other) {
        // Do something
    }
    return *this;
}

void PmergeMe::MergeInsertSort(std::vector<size_t> &vector) {
    if(vector.begin() < vector.end())
}


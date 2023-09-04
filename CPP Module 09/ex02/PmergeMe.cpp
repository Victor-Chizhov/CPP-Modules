#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &copy) {
    *this = copy;
}
PmergeMe::~PmergeMe() {}
PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {
    (void)copy;
    return *this;
}

void PmergeMe::MergeInsertSortVector(std::vector<size_t> &_vector) {
    if (_vector.size() <= 1)
        return;

    std::vector<size_t> left;
    std::vector<size_t> right;

    for (size_t i = 0; i < _vector.size() / 2; i++) {
        left.push_back(_vector[i]);
    }
    for (size_t i = _vector.size() / 2; i < _vector.size(); i++) {
        right.push_back(_vector[i]);
    }
    MergeInsertSortVector(left);
    MergeInsertSortVector(right);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            _vector[k] = left[i];
            i++;
        } else {
            _vector[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left.size()) {
        _vector[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size()) {
        _vector[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::pushVector(const size_t &value, std::vector<size_t> &_vector) {
    _vector.push_back(value);
}

void PmergeMe::printVector(std::vector<size_t> &_vector) {
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i];
        if (i < _vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}






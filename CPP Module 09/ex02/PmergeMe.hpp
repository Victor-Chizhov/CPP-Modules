#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>

class PmergeMe {

    private:
        std::vector<size_t> _vector;
        std::deque<size_t> _deque;

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe const &other);
        void MergeInsertSort(std::vector<size_t> &vector);
        void MergeInsertSort(std::deque<size_t> &deque);
};

#endif
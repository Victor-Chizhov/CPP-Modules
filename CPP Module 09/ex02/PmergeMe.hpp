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
        PmergeMe();
        PmergeMe(PmergeMe const &copy);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe const &copy);

    public:
        static void MergeInsertSortVector(std::vector<size_t> &arr);
        static void pushVector(const size_t &value, std::vector<size_t> &_vector);
        static void printVector(std::vector<size_t> &_vector);
};

#endif
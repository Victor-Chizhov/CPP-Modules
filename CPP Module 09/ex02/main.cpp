#include "PmergeMe.hpp"

int main(int ac, char **av) {

    if (ac < 2) {
        std::cout << "Usage: ./ex02 [value]" << std::endl;
        return 1;
    }

    std::vector<size_t> _vector;

    for (int i = 1; i < ac; i++) {
        try {
            PmergeMe::pushVector(std::stoi(av[i]), _vector);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    PmergeMe::MergeInsertSortVector(_vector);
    PmergeMe::printVector(_vector);
}
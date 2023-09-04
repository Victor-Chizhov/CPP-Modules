#include "PmergeMe.hpp"

int main(int ac, char **av) {

    if (ac < 2) {
        std::cout << "Usage: ./ex02 [value]" << std::endl;
        return 1;
    }

    std::vector<int> _vector;
    std::deque<int> _deque;

    for (int i = 1; i < ac; i++) {

        for (size_t j = 0; j < strlen(av[i]); j++) {
            if (!isdigit(av[i][j])) {
                std::cout << "Error" << std::endl;
                return 1;
            }
        }
        try {
            push(std::stoi(av[i]), _vector);
            push(std::stoi(av[i]), _deque);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    std::cout << "Before: ";
    print(_vector);
    clock_t start = clock();
    mergeInsertSortVector(_vector);
    clock_t end = clock();
    std::cout << "After:  ";
    print(_vector);
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<int> " << std::fixed << duration << " us" << std::endl;

    start = clock();
    mergeInsertSortDeque(_deque);
    end = clock();
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque<int> " << std::fixed << duration << " us" << std::endl;
    return 0;
}
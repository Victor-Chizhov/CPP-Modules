#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(i);
    }
    try {
        easyfind(numbers, 5);
        easyfind(numbers, 10);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
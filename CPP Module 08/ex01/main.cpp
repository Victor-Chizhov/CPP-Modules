#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(2);
    sp.addNumber(1);
    sp.addNumber(6);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::vector<int> arr(10000);
    srand(time(NULL));
    generate(arr.begin(), arr.end(), rand);
    try {
        Span sp2 = Span(990);
        sp2.rangeOfIterator(arr.begin(), arr.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;

}
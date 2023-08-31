#include "Span.hpp"

Span::Span() {
    _n = 0;
}

Span::Span(unsigned int n) {
    _n = n;
    _container(n);
}

Span::Span(const Span& copy) {
    *this = copy;
}

Span& Span::operator=(const Span& copy) {
    if (this != &copy) {
        _n = copy._n;
        _container = copy._container;
    }
    return *this;
}

Span::~Span() {

}

void Span::addNumber(int num) {
    if (_container.size() < _n) {
        _container.push_back(num);
    }
    else {
        throw std::out_of_range("Container is full");
    }
}

int Span::shortestSpan() {
    if (_container.size() < 2) {
        throw std::out_of_range("Container is too small");
    }
    std::vector<int> copy = _container;
    std::sort(copy.begin(), copy.end());
    int shortest = copy[1] - copy[0];
    for (unsigned int i = 1; i < copy.size(); i++) {
        if (copy[i] - copy[i - 1] < shortest) {
            shortest = copy[i] - copy[i - 1];
        }
    }
    return shortest;
}

int Span::longestSpan() {
    if (_container.size() < 2) {
        throw std::out_of_range("Container is too small");
    }
    std::vector<int> copy = _container;
    std::sort(copy.begin(), copy.end());
    return copy[copy.size() - 1] - copy[0];
}

void Span::rangeOfIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    unsigned int remainingCapacity = _numbers.capacity() - _numbers.size();
    unsigned int rangeSize = std::distance(begin, end);

    if (rangeSize <= remainingCapacity) {
        _numbers.insert(_numbers.end(), begin, end);
    }
    else {
        throw std::runtime_error("Not enough space in Span to add the entire range");
    }
}


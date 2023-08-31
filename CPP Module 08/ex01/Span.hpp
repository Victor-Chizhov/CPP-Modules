#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _container;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        void rangeOfIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end);



};

#endif
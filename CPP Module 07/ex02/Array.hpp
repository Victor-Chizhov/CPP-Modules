#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

    template <typename T> class Array {

    private:
        T *_array;
        unsigned int _n;

    public:
        Array();
        Array(unsigned int);
        Array(const Array&);
        Array& operator=(const Array&);
        ~Array();

};

#endif
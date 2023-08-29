#include "Array.hpp"

Array::Array() {
    T *_array = new T[0];
    _n = 0;
}

Array::Array(unsigned int n) {
    T *_array = new T[n];
    _n = n;
}

Array::Array(const Array &copy) {
    T *_array = new T[copy._n];
    _n = copy._n;
    for (unsigned int i = 0; i < copy._n; i++) {
        _array[i] = copy._array[i];
    }
}

Array& Array::operator=(const Array &copy) {
    if (this != &copy) {
        delete[] _array;
        _array = new T[copy._n];
        _n = copy._n;
        for (unsigned int i = 0; i < copy._n; i++) {
            _array[i] = copy._array[i];
        }
    }
    return *this;
}

Array::~Array() {
    delete[] _array;
}

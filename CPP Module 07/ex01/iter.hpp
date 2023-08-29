#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T*, size_t, void (*f)(T&));
template <typename T, typename U> void iter(const T*, const size_t, U&);
template <typename T> void print(T&);

#endif
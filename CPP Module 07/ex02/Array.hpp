#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>
class Array {

    private:
        T *_array;
        unsigned int _n;

    public:
        Array();
        Array(unsigned int);
        Array(const Array &);
        Array &operator=(const Array &);
        ~Array();
        T &operator[](unsigned int);
        unsigned int size() const;

        class OutOfLimitsException : public std::exception {
        public:
            virtual const char *what() const throw();

        };
};

#include "Array.tpp"


#endif
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(MutantStack const &src);
        MutantStack& operator=(MutantStack const &src);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
        iterator rbegin();
        iterator rend();
        iterator cbegin();
        iterator cend();
        iterator crbegin();
        iterator crend();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src) {
    *this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const &src) {
    if (this != &src) {
        std::stack<T>::operator=(src);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin() {
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend() {
    return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::cbegin() {
    return std::stack<T>::c.cbegin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::cend() {
    return std::stack<T>::c.cend();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::crbegin() {
    return std::stack<T>::c.crbegin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::crend() {
    return std::stack<T>::c.crend();
}



#endif
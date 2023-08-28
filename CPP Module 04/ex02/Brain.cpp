#include "Brain.hpp"

Brain::Brain() {
    std::cout << GREEN1 << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain( const Brain &p ) {
    std::cout << GREEN1 << "Brain copy constructor called" << RESET << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = p._ideas[i];
}

Brain& Brain::operator=( const Brain &p ) {
    std::cout << GREEN1 << "Brain copy assignment operator called" << RESET << std::endl;
    if (this != &p)
        for (int i = 0; i < 100; i++)
            _ideas[i] = p._ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << GREEN1 << "Brain destructor called" << RESET << std::endl;
}

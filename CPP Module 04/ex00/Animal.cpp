#include "Animal.hpp"

Animal::Animal() {
    std::cout << GREEN1 << "Animal default constructor called" << RESET << std::endl;
    this->type = "Animal";
}

Animal::Animal( std::string type ) {
    std::cout << GREEN1 << "Animal name constructor called" << RESET << std::endl;
    this->type = type;
}

Animal::Animal( const Animal &p ) {
    std::cout << GREEN1 << "Animal copy constructor called" << RESET << std::endl;
    *this = p;
}

Animal& Animal::operator=( const Animal &p ) {
    std::cout << GREEN1 << "Animal copy assignment operator called" << RESET << std::endl;
    if (this != &p) {
        this->type = p.type;
    }
    return *this;
}   

Animal::~Animal() {
    std::cout << GREEN1 << "Animal destructor called" << RESET << std::endl;
}

std::string Animal::getType( void ) const {
    return type;
}

void Animal::setType( std::string const type ) {
    this->type = type;
}

void Animal::makeSound() const {
    std::cout << RED1 << "Animal make sound" << RESET << std::endl;
}

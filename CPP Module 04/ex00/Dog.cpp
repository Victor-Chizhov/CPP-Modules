#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << GREEN1 << "Dog default constructor called" << RESET << std::endl;
    this->type = "Dog";
}

Dog::Dog( std::string type ) : Animal( type ) {
    std::cout << GREEN1 << "Dog name constructor called" << RESET << std::endl;
    this->type = type;
}

Dog::Dog( const Dog &p ) : Animal( p ) {
    std::cout << GREEN1 << "Dog copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=( const Dog &p ) {
    std::cout << GREEN1 << "Dog copy assignment operator called" << RESET << std::endl;
    if (this != &p) {
        Animal::operator = (p);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << GREEN1 << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << RED1 << "Dog make noise Gav" << RESET << std::endl;
}
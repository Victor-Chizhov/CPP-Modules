#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << GREEN1 << "Cat default constructor called" << RESET << std::endl;
    this->type = "Cat";
}

Cat::Cat( std::string type ) : Animal( type ) {
    std::cout << GREEN1 << "Cat name constructor called" << RESET << std::endl;
    this->type = type;
}

Cat::Cat( const Cat &p ) : Animal( p ) {
    std::cout << GREEN1 << "Cat copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=( const Cat &p ) {
    std::cout << GREEN1 << "Cat copy assignment operator called" << RESET << std::endl;
    if (this != &p) {
        Animal::operator = (p);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << GREEN1 << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << RED1 << "Cat make noise Meeeow" << RESET << std::endl;
}
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << GREEN1 << "WrongCat default constructor called" << RESET << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat( std::string type ) : WrongAnimal( type ) {
    std::cout << GREEN1 << "WrongCat name constructor called" << RESET << std::endl;
    this->type = type;
}

WrongCat::WrongCat( const WrongCat &p ) : WrongAnimal( p ) {
    std::cout << GREEN1 << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat &p ) {
    std::cout << GREEN1 << "WrongCat copy assignment operator called" << RESET << std::endl;
    if (this != &p) {
        WrongAnimal::operator = (p);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << GREEN1 << "WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << RED1 << "WrongCat make noise Meeeow" << RESET << std::endl;
}
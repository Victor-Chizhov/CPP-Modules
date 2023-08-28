#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << GREEN1 << "WrongAnimal default constructor called" << RESET << std::endl;
    this->type = "Animal";
}

WrongAnimal::WrongAnimal( std::string type ) {
    std::cout << GREEN1 << "WrongAnimal name constructor called" << RESET << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal( const WrongAnimal &p ) {
    std::cout << GREEN1 << "WrongAnimal copy constructor called" << RESET << std::endl;
    *this = p;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &p ) {
    std::cout << GREEN1 << "WrongAnimal copy assignment operator called" << RESET << std::endl;
    if (this != &p) {
        this->type = p.type;
    }
    return *this;
}   

WrongAnimal::~WrongAnimal() {
    std::cout << GREEN1 << "WrongAnimal destructor called" << RESET << std::endl;
}

std::string WrongAnimal::getType( void ) const {
    return type;
}

void WrongAnimal::setType( std::string const type ) {
    this->type = type;
}

void WrongAnimal::makeSound() const {
    std::cout << RED1 << "WrongAnimal make sound" << RESET << std::endl;
}
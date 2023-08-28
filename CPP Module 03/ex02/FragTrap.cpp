#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << GREEN1 << "FragTrap default constructor called" << GREEN2 << std::endl;
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 100;
    _attakDamage = 30; 
}

FragTrap::FragTrap( std::string _name ) : ClapTrap( _name ) {
    std::cout << GREEN1 << "FragTrap name constructor called" << GREEN2 << std::endl;
    this->_name = _name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attakDamage = 30;
}

FragTrap::FragTrap( const FragTrap& p ) : ClapTrap( p ) {
    std::cout << GREEN1 << "FragTrap copy constructor called" << GREEN2 << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& p ) {
    std::cout << GREEN1 << "FragTrap copy assignment operator called" << GREEN2 << std::endl;
    if (this != &p) {
        ClapTrap::operator = (p);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << GREEN1 << "FragTrap destructor called" << GREEN2 << std::endl;
}

void FragTrap::highFivesGuys( void ) {
    std::cout << RED1 << "FragTrap High fives" << RED1 << std::endl;
}
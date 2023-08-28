
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << GREEN1 << "ScavTrap default constructor called" << GREEN2 << std::endl;
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attakDamage = 20; 
}

ScavTrap::ScavTrap( std::string _name ) : ClapTrap( _name ) {
    std::cout << GREEN1 << "ScavTrap name constructor called" << GREEN2 << std::endl;
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attakDamage = 20; 
}

ScavTrap::ScavTrap( const ScavTrap &p ) : ClapTrap( p ) {
    std::cout << GREEN1 << "ScavTrap copy constructor called" << GREEN2 << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &p ) {
    std::cout << GREEN1 << "ScavTrap copy assignment operator called" << GREEN2 << std::endl;
    if (this != &p) {
        ClapTrap::operator = (p);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << GREEN1 << "ScavTrap destructor called" << GREEN2 << std::endl;
}

void ScavTrap::attack( const std::string& target ) {
    _energyPoints -= 1;
    if (_energyPoints < 0) {
        std::cout << BLUE1 << "ScavTrap " << _name << BLUE1 << GREEN1 <<  "doesn't have energy points" << GREEN2 << std::endl;
        _energyPoints += 1;
    }
    std::cout << BLUE1 << "ScavTrap " << _name << BLUE1 << GREEN1 << " attacks " << GREEN2 << BLUE1 << target << BLUE2 << GREEN1 << ", causing " << GREEN2 << RED1 << _attakDamage  << RED2 << GREEN1 << "  points of damage!" << GREEN2 << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << RED1 << "ScavTrap is now in Gate keeper mode" << RED2 << std::endl;
}
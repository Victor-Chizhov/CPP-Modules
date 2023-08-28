#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    std::cout << GREEN1 << "DiamondTrap default constructor called" << GREEN2 << std::endl;
    _name = "default";
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attakDamage = FragTrap::_attakDamage;
}

DiamondTrap::DiamondTrap( std::string _name ) : ClapTrap( _name ), ScavTrap( _name ), FragTrap( _name )  {
    std::cout << GREEN1 << "DiamondTrap name constructor called" << GREEN2 << std::endl;
    this->_name = _name;
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attakDamage = FragTrap::_attakDamage;
}

DiamondTrap::DiamondTrap( const DiamondTrap& p ) : ScavTrap( p ), FragTrap( p ) {
    std::cout << GREEN1 << "DiamondTrap copy constructor called" << GREEN2 << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& p ) {
    std::cout << GREEN1 << "DiamondTrap copy assignment operator called" << GREEN2 << std::endl;
    if (this != &p) {
        ScavTrap::operator = (p);
        FragTrap::operator = (p);
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << GREEN1 << "DiamondTrap destructor called" << GREEN2 << std::endl;
}

void DiamondTrap::attack( const std::string& target ) {
    ScavTrap::attack( target );
}

void DiamondTrap::whoAmI() {
    std::cout << RED1 << _name << " name and its ClapTrap name " << ClapTrap::getName() << std::endl; 
}  
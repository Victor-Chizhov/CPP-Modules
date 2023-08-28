#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << GREEN1 << "ClapTrap default constructor called" << GREEN2 << std::endl;
    this->_name = "default";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attakDamage = 0;
}

ClapTrap::ClapTrap(std::string _name) {
    std::cout << GREEN1 << "ClapTrap name constructor called" << GREEN2 << std::endl;
    this->_name = _name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attakDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &p ) {
    std::cout << GREEN1 << "ClapTrap copy constructor called" << GREEN2 << std::endl;
    *this = p;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &p ) {
    std::cout << GREEN1 << "ClapTrap copy assignment operator called" << GREEN2 << std::endl;
    if (this != &p) {
        _name = p._name;
        _hitPoints = p._hitPoints;
        _energyPoints = p._energyPoints;
        _attakDamage = p._attakDamage;
    }
    return *this;
}   

ClapTrap::~ClapTrap() {
    std::cout << GREEN1 << "ClapTrap destructor called" << GREEN2 << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    _energyPoints -= 1;
    if (_energyPoints < 0) {
        std::cout << BLUE1 << _name << BLUE1 << GREEN1 <<  "doesn't have energy points" << GREEN2 << std::endl;
        _energyPoints += 1;
    }
    std::cout << BLUE1 << _name << BLUE1 << GREEN1 << " attacks " << GREEN2 << BLUE1 << target << BLUE2 << GREEN1 << ", causing " << GREEN2 << RED1 << _attakDamage  << RED2 << GREEN1 << "  points of damage!" << GREEN2 << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;
    if (_hitPoints <= 0) {
        std::cout << BLUE1 << _name << BLUE1 << GREEN1 << " is dead" << GREEN2 << std::endl;
        return ;
    }
    std::cout << BLUE1 << _name << BLUE1 << GREEN1 << " get damage " << GREEN2 << RED1 << amount << RED2 << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount) {
    _energyPoints -= 1;
    if (_energyPoints < 0) {
        std::cout  << BLUE1 << _name << BLUE1 << GREEN1 << " doesn't have energy points" << GREEN2 << std::endl;
        _energyPoints += 1;
        return ;
    }
    _hitPoints += amount;
    std::cout << BLUE1 << _name << BLUE1 << GREEN1 << " has recovered hit points: " << GREEN2 << RED1 << amount << RED2 << GREEN1 << " and now have HP: " << GREEN1 << RED1 << _hitPoints << RED2 << std::endl; 
}

std::string ClapTrap::getName( void ) const {
    return _name;
}

void ClapTrap::setName( std::string const _name ) {
    this->_name = _name;
}

int ClapTrap::getHitPoints( void ) const {
    return _hitPoints;
}

void ClapTrap::setHitPoints( int const _hitPoints ) {
    this->_hitPoints = _hitPoints;
}

int ClapTrap::getEnergyPoints( void ) const {
    return _energyPoints;
}

void ClapTrap::setEnergyPoints( int const _energyPoints ) {
    this->_energyPoints = _energyPoints;
}

int ClapTrap::getAttakDamage( void ) const {
    return _attakDamage;
}

void ClapTrap::setAttakDamage( int const _attakDamage ) {
    this->_attakDamage = _attakDamage;
}


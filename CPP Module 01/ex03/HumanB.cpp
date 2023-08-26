#include "HumanB.hpp"

void HumanB::attack() { std::cout << _name << "  attacks with their " << _gun->getType() << std::endl; }

HumanB::HumanB( std::string _name ) { this->_name = _name; }
HumanB::HumanB( std::string _name, Weapon &_gun ) {
    this->_name = _name;
    this->_gun = &_gun;
}
HumanB::~HumanB() {}

void HumanB::setWeapon( Weapon& _gun ) { this->_gun = &_gun; }
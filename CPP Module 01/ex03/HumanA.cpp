#include "HumanA.hpp"

void HumanA::attack() { std::cout << _name << "  attacks with their " << _gun.getType() << std::endl; }

HumanA::HumanA( std::string _name, Weapon &_gun ) : _gun(_gun) {
    this->_name = _name;
}

HumanA::~HumanA() {}
#include "Weapon.hpp"

const std::string& Weapon::getType() { return _type; }
void Weapon::setType(std::string _type) { this->_type = _type; }

Weapon::Weapon(std::string _type) { this->_type = _type; }
Weapon::Weapon() {}
Weapon::~Weapon() {}
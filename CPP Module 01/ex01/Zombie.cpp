#include "Zombie.hpp"

void Zombie::announce() { std::cout << _name.data() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

std::string Zombie::getName() { return _name; }
void Zombie::setName(std::string _name) { this->_name = _name; }

Zombie::Zombie() {}

Zombie::Zombie(std::string _name) { this->_name = _name; }

Zombie::~Zombie() {std::cout << _name << ": is dead" << std::endl; }
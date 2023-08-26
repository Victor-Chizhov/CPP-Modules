#include "Zombie.hpp"

void Zombie::announce() { std::cout << _name.data() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

Zombie::Zombie() {}

Zombie::Zombie(std::string _name) { this->_name = _name; }

Zombie::~Zombie() {std::cout << _name << ": is dead" << std::endl; }
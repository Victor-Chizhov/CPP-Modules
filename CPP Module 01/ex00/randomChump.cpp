#include "Zombie.hpp"

void randomChump( std::string name ) {
    Zombie zombieOnStack(name);
    zombieOnStack.announce();
}
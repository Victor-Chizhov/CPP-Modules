#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
    Zombie *zombieOnHeap = new Zombie(name);
    return zombieOnHeap;
}
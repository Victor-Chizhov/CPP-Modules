#include "Zombie.hpp"

int main() {

    Zombie *a = newZombie( "Shaun1" );
    a->announce();

    randomChump( "Shaun2" );

    Zombie b( "Shaun3" );
    b.announce();
    delete a;
    return 0;
}
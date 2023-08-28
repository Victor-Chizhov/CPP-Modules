#include "ClapTrap.hpp"

int main() {

    ClapTrap a("Uchiha Madara");
    ClapTrap b("Uchiha Obito");
    a.attack(b.getName());
    b.takeDamage(a.getAttakDamage());
    b.beRepaired(5);
    b.attack(a.getName());
    a.takeDamage(b.getAttakDamage());
    a.beRepaired(7);

    return 0;
}
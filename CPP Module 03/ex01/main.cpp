#include "ScavTrap.hpp"

int main() {

    ClapTrap a("Uchiha Madara");
    ClapTrap b("Uchiha Obito");
    ScavTrap c("Uchiha Itachi");
    a.attack(b.getName());
    b.takeDamage(a.getAttakDamage());
    b.beRepaired(5);
    b.attack(a.getName());
    a.takeDamage(b.getAttakDamage());
    a.beRepaired(7);

    c.attack(a.getName());
    c.takeDamage(a.getAttakDamage());
    c.beRepaired(10);

    return 0;
}
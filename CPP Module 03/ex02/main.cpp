#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    ClapTrap a("Uchiha Madara");
    std::cout << std::endl;

    ClapTrap b("Uchiha Obito");
    std::cout << std::endl;

    ScavTrap c("Uchiha Itachi");
    std::cout << std::endl;

    FragTrap d("Uchiha Sasuke");
    std::cout << std::endl;
    
    a.attack(b.getName());
    a.takeDamage(b.getAttakDamage());
    a.beRepaired(7);
    std::cout << std::endl;

    b.attack(a.getName());
    b.takeDamage(a.getAttakDamage());
    b.beRepaired(5);
    std::cout << std::endl;

    c.attack(a.getName());
    c.takeDamage(a.getAttakDamage());
    c.beRepaired(10);
    c.guardGate();
    std::cout << std::endl;

    d.attack(c.getName());
    d.takeDamage(c.getAttakDamage());
    d.beRepaired(10);
    d.highFivesGuys();
    std::cout << std::endl;
    
    return 0;
}
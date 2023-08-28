#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RED1 "\033[31m"
#define RED2 "\033[0m"
#define GREEN1 "\033[32m"
#define GREEN2 "\033[0m"
#define YELLOW1 "\033[33m"
#define YELLOW2 "\033[0m"
#define BLUE1 "\033[34m"
#define BLUE2 "\033[0m"


class ClapTrap {

    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attakDamage;

    public:

        ClapTrap();
        ClapTrap(std::string _name);
        ClapTrap( const ClapTrap &p );
        ClapTrap& operator=( const ClapTrap &p );
        ~ClapTrap();

        std::string getName( void ) const;
        void setName( std::string const _name );
        int getHitPoints( void ) const;
        void setHitPoints( int const _hitPoints );
        int getEnergyPoints( void ) const;
        void setEnergyPoints( int const _energyPoints );
        int getAttakDamage( void ) const;
        void setAttakDamage( int const _attakDamage );

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};


#endif
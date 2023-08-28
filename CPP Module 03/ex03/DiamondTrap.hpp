#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap {

    private:
        std::string _name;
    
    public:
        DiamondTrap();
        DiamondTrap( std::string _name );
        DiamondTrap( const DiamondTrap& p );
        DiamondTrap& operator=( const DiamondTrap& p );
        ~DiamondTrap();

        void attack( const std::string& target );
        void whoAmI(); 


};

#endif
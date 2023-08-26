#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

    private:
        std::string _name;
        Weapon* _gun;

    public:
        void attack();
        HumanB( std::string _name );
        HumanB( std::string _name, Weapon &_gun );
        ~HumanB();
        void setWeapon( Weapon &_gun );
};



#endif
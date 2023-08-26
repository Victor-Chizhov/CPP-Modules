#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

    private:
        std::string _name;
        Weapon &_gun;
    
    public:
        void attack();
        HumanA( std::string _name, Weapon &_gun );
        ~HumanA();

};


#endif
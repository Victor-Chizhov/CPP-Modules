#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

    private:
        std::string _type;

    public:
        const std::string& getType();
        void setType(std::string _type);
        Weapon(std::string _type);
        Weapon();
        ~Weapon();
};


#endif
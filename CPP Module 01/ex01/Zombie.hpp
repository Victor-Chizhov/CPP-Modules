#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    
    private: 
        std::string _name;

    public:
        Zombie();
        Zombie(std::string _name);
        ~Zombie();
        void announce( void );
        void setName(std::string _name);
        std::string getName();

};

Zombie* zombieHorde( int N, std::string name );

#endif
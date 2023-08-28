#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    private:


    public:
        FragTrap();
        FragTrap( std::string _name );
        FragTrap( const FragTrap &p );
        FragTrap& operator=( const FragTrap &p );
        ~FragTrap();

        void highFivesGuys( void );



};


#endif




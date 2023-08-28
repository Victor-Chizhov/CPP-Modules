#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    private:

    public:
        WrongCat();
        WrongCat (std::string type );
        WrongCat( const WrongCat &p );
        WrongCat& operator=( const WrongCat &p );
        ~WrongCat();
        void makeSound() const;


};

#endif
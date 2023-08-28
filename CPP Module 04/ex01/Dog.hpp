#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal {
    
    private:
        Brain* _brain;

    public:
        Dog();
        Dog (std::string type );
        Dog( const Dog &p );
        Dog& operator=( const Dog &p );
        virtual ~Dog();

        void makeSound() const;

};


#endif
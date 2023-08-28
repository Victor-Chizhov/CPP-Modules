#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    
    private:

    public:
        Cat();
        Cat (std::string type );
        Cat( const Cat &p );
        Cat& operator=( const Cat &p );
        virtual ~Cat();
        void makeSound() const;
};


#endif
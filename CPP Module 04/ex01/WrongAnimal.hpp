#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


#include <iostream>

#define RED1 "\033[31m"
#define GREEN1 "\033[32m"
#define YELLOW1 "\033[33m"
#define BLUE1 "\033[34m"
#define RESET "\033[0m"

class WrongAnimal {

    protected:
        std::string type;

    public:

        WrongAnimal();
        WrongAnimal( std::string type );
        WrongAnimal( const WrongAnimal &p );
        WrongAnimal& operator=( const WrongAnimal &p );
        virtual ~WrongAnimal();

        std::string getType( void ) const;
        void setType( std::string const type );
        
        void makeSound() const;

};


#endif
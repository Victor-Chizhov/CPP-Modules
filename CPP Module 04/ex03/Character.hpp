#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {

    private:
        std::string _name;
        AMateria *_inventory[4];

    public:
        Character();
        Character(std::string const &name);
        Character(Character const &copy);
        Character& operator=(Character const &copy);
        virtual ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
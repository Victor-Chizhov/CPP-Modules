#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {

    private:
        AMateria* _materia[4];

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &copy);
        virtual ~MateriaSource(void);
        MateriaSource & operator=(MateriaSource const &copy);

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const &type);


};

#endif
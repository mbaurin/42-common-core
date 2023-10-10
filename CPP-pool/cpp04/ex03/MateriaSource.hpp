#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & a);
        virtual ~MateriaSource();

        MateriaSource & operator=(MateriaSource const & a);

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);

    private:
        int _nb;
        AMateria* _materias[4];

};

#endif
#include "MateriaSource.hpp"

//////////

MateriaSource::MateriaSource()
{
    _nb = 0;
    for (int i = 0; i < 4; i++)
        _materias[i] = nullptr;
    std::cout << "MateriaSource Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & a)
{
    for (int i = 0; i < 4; i++)
        learnMateria(a._materias[i]->clone());
    for (int i = 0; i < 4; i++)
        _materias[i] = nullptr;
    std::cout << "MateriaSource Copy Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _materias[i];
    std::cout << "MateriaSource Destructor Called" << std::endl;
}

//////////

MateriaSource & MateriaSource::operator=(MateriaSource const & a)
{
    for (int i = 0; i < _nb; i++)
        delete _materias[i];
    for (int i = 0; i < a._nb; i++)
        learnMateria(a._materias[i]->clone());
    for (int i = a._nb; i < 4; i++)
        _materias[i] = nullptr;
    return *this;
}

//////////

void MateriaSource::learnMateria(AMateria* m)
{
    if (_nb < 3 && _materias != nullptr)
    {
        for (int i = 0; i < _nb; i++)
            if (_materias[i] == m)
                return ;
        _materias[_nb] = m;
        _nb++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _nb; i++)
        if (_materias[i]->getType() == type)
            return (_materias[i]->clone());
    return nullptr;
}


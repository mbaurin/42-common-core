#include "Character.hpp"

//////////

Character::Character()
{
    std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(std::string const & name)
{
    _name = name;
    _nbMateria = 0;
    for (int i = 0; i < 4; i++)
        _materia[i] = nullptr;
    std::cout << "Character " << _name << " Constructor Called" << std::endl;
}

Character::Character(Character const & a)
{
    _name = a._name;
    _nbMateria = 0;
    for (int i = 0; i < a._nbMateria; i++)
        _materia[i] = nullptr;
    for (int i = 0; i < a._nbMateria; i++)
        equip(a._materia[i]->clone());
    std::cout << "Character " << _name << " Copy Constructor Called" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < _nbMateria; i++)
        delete _materia[i];
    std::cout << "Character " << _name << " Destructor Called" << std::endl;
}

//////////

Character & Character::operator=(Character const & a)
{
    _name = a._name;
    for (int i = 0; i < _nbMateria; i++)
    {
        unequip(i);
        delete _materia[i];
    }
    for (int i = 0; i < a._nbMateria; i++)
        equip(a._materia[i]->clone());
    for (int i = _nbMateria; i < 4; i++)
        _materia[i] = nullptr;
    return *this;
}

//////////

std::string const & Character::getName() const
{
    return _name;
}

//////////

void Character::equip(AMateria* m)
{
    if (_nbMateria < 3 && m != nullptr)
    {
        for (int i = 0; i < _nbMateria; i++)
            if (_materia[i] == m)
                return ;
        _materia[_nbMateria] = m;
        _nbMateria++;
    }
}

void Character::unequip(int idx)
{
    if (idx > 0 && _nbMateria > 0 && _materia[idx] != nullptr)
    {
        for (int i = idx; i < 3; i++)
        {
            _materia[i] = _materia[i + 1];
            _materia[i + 1] = nullptr;
        }
        _nbMateria--;
    }
}

void Character::use(int idx, ICharacter & target)
{
    _materia[idx]->use(target);
}

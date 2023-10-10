#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main()
{
    std::cout << "----------" << std::endl;
    IMateriaSource* src = new MateriaSource();

    std::cout << std::endl;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "----------" << std::endl;

    ICharacter* me = new Character("josé");
    ICharacter* bob = new Character("emile");
    
    std::cout << "----------" << std::endl;

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << "----------" << std::endl;
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    std::cout << "----------" << std::endl;
    delete bob;
    delete me;
    delete src;
    std::cout << "----------" << std::endl;
    
    return 0;
}
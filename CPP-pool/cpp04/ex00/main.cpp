#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();


    std::cout << "----------" << std::endl;
    std::cout << "Type: " << i->getType() << std::endl;
    std::cout << "Type: " << j->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << "----------" << std::endl;

    delete meta;
    delete i;
    delete j;

    std::cout << std::endl;

    const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	std::cout << "----------" << std::endl;
    meta2->makeSound();
    i2->makeSound();
    std::cout << "----------" << std::endl;

    delete i2;
    delete meta2;

    return 0;
}
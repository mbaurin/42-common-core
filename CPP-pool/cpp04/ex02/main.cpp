#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* animals[6];

	for (int i = 0; i < 3; i++)
		animals[i] =  new Dog();
    std::cout << "-----" << std::endl;
	for (int i = 3; i < 6; i++)
		animals[i] =  new Cat();
	std::cout << "-----" << std::endl;
    for (int i = 0; i < 6; i++)
		delete animals[i];
    std::cout << "-----" << std::endl;

	Dog	a;
	Dog b;

	b = a;
    std::cout << "-----" << std::endl;
	std::cout << "Address of brain a: " << (a.getBrain()) << std:: endl;
	std::cout << "Address of brain b: " << (b.getBrain()) << std:: endl;
    std::cout << "-----" << std::endl;
}
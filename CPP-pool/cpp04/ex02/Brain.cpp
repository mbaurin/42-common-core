#include "Brain.hpp"

//////////

Brain::Brain()
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(Brain const & a)
{
    (void)(a);
    std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

//////////

Brain & Brain::operator=(Brain const & a)
{
    if (&a == this)
        return *this;
    std::copy(a._ideas, a._ideas + 100, _ideas);
    return *this;
}

//////////

std::string* Brain::getIdeas()
{
    return _ideas;
}
#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(Brain const & a);
        ~Brain();

        Brain & operator=(Brain const &);

        std::string* getIdeas();

    private:
        std::string _ideas[100];
};

#endif
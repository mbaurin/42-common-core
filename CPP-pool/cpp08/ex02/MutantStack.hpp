#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <string>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:

        //////////

        MutantStack()
        {

        }

        MutantStack(const MutantStack<T> & a)
        {
            *this = a;
        }

        ~MutantStack()
        {

        }

        //////////

        MutantStack & operator=( const MutantStack<T> & a)
        {
            *this->c = a.c;
            return *this;
        }

        //////////

        typedef typename std::stack<T>::container_type::iterator iterateur;

        iterateur begin()
		{
			return this->c.begin();
		}

		iterateur end()
		{
			return this->c.end();
		}
};

#endif
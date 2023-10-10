#ifndef SPAN_H
#define SPAN_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class limitException : public std::exception
{
    public: 
        virtual const char *what() const throw()
        {
            return "Limit reached";
        }
};

class	storageEmptyException : public std::exception
{
	virtual const char *what() const throw()
	{
		return "Not enought numbers to have a Span";
    }
};

class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(Span const & a);
        ~Span();

        Span & operator=(Span const & a);

        std::vector<int> & getVector();

        void addNumber(int n);
        void addAll(int a, int z);

        int shortestSpan();
        int longestSpan();

    private:
        std::vector<int> _vector;
        unsigned int _size;

};

std::ostream & operator<<(std::ostream & o, Span & a);

#endif
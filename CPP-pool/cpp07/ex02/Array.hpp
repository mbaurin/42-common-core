#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>

class outOfLimit: public std::exception
{
    public:
	    virtual const char* what() const throw()
	    {
		    return "Index out of limits";
	    }
};

template <typename T>
class Array
{
    public :

    ////////////////////
    
        Array()
        {
            _tab = new T[0];
            _size = 0;
        }

        Array(unsigned int n)
        {
            _tab = new T[n];
            _size = n;
        }

        Array(Array & a)
        {
            _size = a._size;
            _tab = new T[_size];
            for (int i = 0; i < a._size; i++)
                _tab[i] = a._tab[i];
        }

        virtual ~Array()
        {
            delete [] _tab;
        }
    
    ////////////////////
    
        Array const & operator=(Array const & a)
        {
            _size = a._size;
            delete [] _tab;
            _tab = new T[_size];
            for (int i = 0; i < a._size; i++)
                _tab[i] = a._tab[i];
            return *this;
        }

        T & operator[](int i) const 
        {
            if (i > this->size())
                throw outOfLimit();
            return _tab[i];
        }
    
    ////////////////////
    
        int size() const 
        {
            return _size;
        }

    private:
        T *_tab;
        int _size;

};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & a)
{
    o << "{";
    for (int i = 0; i < a.size(); i++)
    {
        if (i < a.size() - 1)
            o << a[i] << ",";
        else
            o << a[i];
    }
    o << "}";   
	return o;
}

#endif

#include "Span.hpp"

//////////

Span::Span()
{
    _vector.assign(0, 0);
    _size = 0;
}

Span::Span(unsigned int n)
{
    _size = n;
}

Span::Span(Span const & a)
{
    _vector.assign(a._vector.begin(), a._vector.end());
    _size = a._size;
}

Span::~Span()
{

}

//////////

Span & Span::operator=(Span const & a)
{
    _vector.assign(a._vector.begin(), a._vector.end());
    _size = a._size;
    return *this;
}

//////////

std::vector<int> & Span::getVector(void)
{
	return _vector;
}

//////////

void Span::addNumber(int n)
{
    if (_vector.size() >= _size)
        throw limitException();
    _vector.push_back(n);
}

void Span::addAll(int a, int z)
{
    long range = z - a;

	if (range < 0)
		range = -range;

	if ((_vector.size() + range) >= _size)
	{
		throw limitException();
		return ;
	}

	int i = a;

	while (i <= z)
	{
		_vector.push_back(i);
		i++;
	}
}

int Span::shortestSpan()
{
    if (_vector.size() <= 1)
		throw storageEmptyException();

	unsigned int i;
	unsigned int j;
	int span = _vector[0] - _vector[1];
	
	if (span < 0)
		span = -span;

	i = 1;
	while (i < _vector.size())
	{
		j = 0;
		while (j < i)
		{
			if (span > _vector[i] - _vector[j])
				span = _vector[i] - _vector[j];
			j++;
		}
		i++;
	}

	return ((span));
}


int Span::longestSpan()
{
	if (_vector.size() <= 1)
		throw storageEmptyException();

	unsigned int i;
	unsigned int j;
	int span = _vector[0] - _vector[1];
	
	if (span < 0)
		span = -span;

	i = 1;
	while (i < _vector.size())
	{
		j = 0;
		while (j < i)
		{
			if (span < _vector[i] - _vector[j])
				span = _vector[i] - _vector[j];
			j++;
		}
		i++;
	}

	return (span);
}

std::ostream & operator<<(std::ostream & o, Span & a)
{
    for (std::vector<int>::iterator i = a.getVector().begin() ; i < a.getVector().end(); i++)
	{
		o << *i << std::endl;
	}
	return o;
}

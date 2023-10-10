#ifndef KAREN_H
#define KAREN_H

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <cctype>
#include <cstring>

class Karen;
typedef void (Karen:: *FnPtr)();

class Karen
{
    public:
        Karen();
        ~Karen();
        void complain( std::string level );
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif
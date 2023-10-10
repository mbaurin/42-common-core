#include "Karen.hpp"

Karen::Karen(void)
{

}

Karen::~Karen(void)
{

}

void Karen::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl << "I really do!" << std::endl << std::endl;
}

void Karen::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger!" << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Karen::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Karen::error( void )
{
    std::cout << "This is unacceptable!" << std::endl << "I want to speak to the manager now." << std::endl << std::endl;
}

void Karen::complain(std::string level)
{
    std::map<std::string, FnPtr> _map;
    _map["debug"] = &Karen::debug;
    _map["info"] = &Karen::info;
    _map["warning"] = &Karen::warning;
    _map["error"] = &Karen::error;

    (this->*_map[level])();
}
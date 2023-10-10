#include "contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName()
{
    std::string line;

    std::cout << "Enter the first name: ";
    std::getline(std::cin, _firstName);
}

void Contact::setLastName()
{
    std::string line;

    std::cout << "Enter the last name: ";
    std::getline(std::cin, _lastName);
}

void Contact::setNickname()
{
    std::string line;

    std::cout << "Enter the nickname: ";
    std::getline(std::cin, _nickname);
}

void Contact::setPhoneNumber()
{
    std::string line;

    std::cout << "Enter the phone number: ";
    std::getline(std::cin, _phoneNumber);
}

void Contact::setDarkestSecret()
{
    std::string line;

    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, _darkestSecret);
}

std::string Contact::getLastName()
{
    return _lastName;
}

std::string Contact::getFirstName()
{
    return _firstName;
}

std::string Contact::getNickname()
{
    return _nickname;
}

std::string Contact::getPhoneNumber()
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return _darkestSecret;
}

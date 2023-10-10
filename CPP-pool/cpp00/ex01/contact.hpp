#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
public:
    Contact();
    ~Contact();
    void setFirstName();
    void setLastName();
    void setNickname();
    void setPhoneNumber();
    void setDarkestSecret();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif
#include "app.hpp"

App::App()
{
}

App::~App()
{
}

int add(Contact *contact)
{
	contact->setFirstName();
	contact->setLastName();
	contact->setNickname();
	contact->setPhoneNumber();
	contact->setDarkestSecret();
	std::cout << "Contact successfully added" << std::endl;
	return 0;
}

int contains_other_than_digit(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (1);
		i++;
	}
    return 0;
}

void show_infos_contact(Contact *contact, int index)
{
	std::cout << "Index: " << index << std::endl;
	std::cout << "First name: " << contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contact[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact[index].getDarkestSecret() << std::endl;
}

static std::string
truncate(std::string field)
{
    field = field.erase((10 - 1), field.length() - (10 - 1));
    field.append(".");
    return (field);
}

void search(Contact *contact, int nb)
{
	std::string temp;
	std::string index_str;
	int index;
	int	i;
	std::string     first_name;
    std::string     last_name;
    std::string     nickname;

	std::cout << "---------------------------------------------" << std::endl;
	i = 0;
	while (i < nb)
	{
		first_name = contact[i].getFirstName();
		last_name = contact[i].getLastName();
		nickname = contact[i].getNickname();
		
		std::cout << "|" << std::setw(10) << i;

		if (first_name.length() > 10)
			first_name = truncate(first_name);
        std::cout << "|" << std::setw(10) << first_name;
		
		if (last_name.length() > 10)
			last_name = truncate(last_name);
		std::cout << "|" << std::setw(10) << last_name;
		
		if (nickname.length() > 10)
			nickname = truncate(nickname);
		std::cout << "|" << std::setw(10) << nickname << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
	if (nb >= 1)
	{
		std::cout << "Enter the index: ";
		while (std::getline(std::cin, index_str))
		{
			index = atoi(index_str.c_str());
			if (contains_other_than_digit(index_str) || index > nb || index < 0 || index > 9)
				std::cout << "Error: Invalid index" << std::endl;
			else
			{
				show_infos_contact(contact, index);
				break;
			}
			std::cout << "Enter the index: ";
		}
	}
}

int	main(void)
{
	std::string line;
	int	nb_contacts = 0;
	App app;

	std::cout << "Welcome to your Contact App, called the app :" << std::endl;
	std::cout << "-> ADD: add a new contact in the app" << std::endl;
	std::cout << "-> SEARCH: show your contact list and their infos" << std::endl;
	std::cout << "-> EXIT: exit the program" << std::endl;
	std::getline(std::cin, line);
	while (line != "EXIT")
	{
		if (line == "SEARCH")
			search(app._list, nb_contacts);
		else if (line == "ADD" && nb_contacts < 7)
			add(&app._list[nb_contacts++]);
		else if (line == "ADD" && nb_contacts >= 7)
			std::cout << "Too much contacts, app is full" << std::endl;
		else
			std::cout << "Error: Unvalid command, please use ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, line);
	}
	std::cout << "You exited the app" << std::endl;
	return 0;
}

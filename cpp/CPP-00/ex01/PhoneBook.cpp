#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _index = 0;
    _counter = 0;
}


std::string PhoneBook::_getInput(std::string prompt)
{
    std::string input;

    while(1)
    {
        std::cout << prompt;
        if(!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            return "";
        }
        if(!input.empty())
        {
            return input;
        }
        std::cout << "Field cannot be empty!" << std::endl;
    }
}

std::string PhoneBook::_formater(std::string str)
{
    if(str.length() > 10)
        return str.substr(0,9) + ".";
    return str;
}

bool PhoneBook::_checkDegit(std::string str)
{
    if (str.empty())
        return false;
    for(size_t i = 0; i < str.length(); i++)
    {
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::add_contact()
{
    Contact newcontact;
    std::string input;

    input = _getInput("First name: ");
    if(input.empty())
        return;
    newcontact.setFirstName(input);
    
    input = _getInput("Last name: ");
    if(input.empty())
        return;
    newcontact.setLastName(input);

    input = _getInput("Nickname: ");
    if(input.empty())
        return;
    newcontact.setNickname(input);

    input = _getInput("PhoneNumber: ");
    if(input.empty())
        return;
    newcontact.setPhoneNumber(input);

    input = _getInput("DarkestSecret: ");
    if(input.empty())
        return;
    newcontact.setDarkestSecret(input);

    _contacts[_index] = newcontact;
    _index = (_index + 1) % 8;
    if(_counter !=  8)
        _counter++;
}
void PhoneBook::_printContact(int index)
{
    std::cout << "First Name: " << _contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << _contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << _contacts[index].getNickname() << "\n" ;
    std::cout << "PhoneNumber: " << _contacts[index].getPhoneNumber() << "\n";
    std::cout << "DarkestSecret: "<< _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::search_contact()
{
    int index = 0;

    if(_counter == 0)
    {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;

    for(int i = 0; i < _counter; i++)
    {
        std::cout << "|" << std::setw(10) << std::right << i;
        std::cout << "|" << std::setw(10) << std::right << _formater(_contacts[i].getFirstName());
        std::cout << "|" << std::setw(10) << std::right << _formater(_contacts[i].getLastName());
        std::cout << "|" << std::setw(10) << std::right << _formater(_contacts[i].getNickname());
        std::cout << "|" << std::endl;
    }

    while(1)
    {
        std::string input = _getInput("Enter Index: ");
        if(input.empty())
            return;
        if (!_checkDegit(input))
        {
            std::cout << "Wrong Input, must be number" << std::endl;
            continue;
        }
        index = std::atoi(input.c_str());
        if(index < _counter && index >= 0)
            break;
        std::cout << "Wrong Index !!" << std::endl;
    }
    _printContact(index);
}
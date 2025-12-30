#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"


class PhoneBook{

private:
    Contact _contacts[8];
    int _index;
    int _counter;
    std::string _getInput(std::string prompt);
    std::string _formater(std::string str);
    bool _checkDegit(std::string str);
    void _printContact(int index);
public:
    PhoneBook();
    void add_contact();
    void search_contact();

};

#endif
#include "PhoneBook.hpp"

int main()
{
    std::string input;
    PhoneBook phonebook;

    while(1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            break;
        }
        if(input.empty())
            continue;
        else if (input == "ADD")
        {
            phonebook.add_contact();
        }
        else if (input == "SEARCH")
        {
            phonebook.search_contact();
        }
        else if (input == "EXIT")
        {
            break;
        }
        else
            continue;
    }
    return 0;
}
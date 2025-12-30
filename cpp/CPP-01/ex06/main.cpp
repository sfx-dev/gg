#include "Harl.hpp"


int main(int ac, char **av)
{
    if(ac != 2)
        return 1;

    Harl harl;
    std::string level = av[1];
    std::string arr[] = {"DEBUG","INFO", "WARNING", "ERROR"};
    int index = 0;

    for(int i = 0; i < 4; i++)
    {
        if(av[1] == arr[i])
        {
            index = i + 1;
            break;
        }
    }
    
    switch (index)
    {
    case 1:
        harl.complain("DEBUG");
        __attribute__((fallthrough));
    case 2:
        harl.complain("INFO");
        __attribute__((fallthrough));
    case 3:
        harl.complain("WARNING");
        __attribute__((fallthrough));
    case 4:
        harl.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}
#include "Harl.hpp"



void Harl::debug()
{
    std::cout << "I love having extra bacon..." << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money..." << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free..." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string Levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
    HarlFunc funptr[4] = {&Harl::debug, &Harl::info, &Harl::warning ,&Harl::error};
    
    for(int i = 0; i < 4; i++)
    {
        if(level == Levels[i])
        {
            (this->*funptr[i])();
            return;
        }
    }
}
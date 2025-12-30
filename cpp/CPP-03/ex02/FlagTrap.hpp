#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap :public ClapTrap
{
    FlagTrap();
    ~FlagTrap();
    FlagTrap(const FlagTrap &obj);
    FlagTrap(std::string name);
    FlagTrap& operator=(const FlagTrap &obj);    
    void highFivesGuys(void);
    void attack(const std::string& target);
};



#endif 
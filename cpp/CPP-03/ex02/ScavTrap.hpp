#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
    ScavTrap();
    ~ScavTrap();
    ScavTrap(const ScavTrap &obj);
    ScavTrap(std::string name);
    ScavTrap& operator=(const ScavTrap &obj);
    void attack(const std::string& target);
    void guardGate();
};



#endif
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{

protected:
    std::string _name;
    unsigned int _hitPoint;
    unsigned int _energyPoint;
    unsigned int _attackDamage;

public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap();
    ~ClapTrap();
    ClapTrap(const ClapTrap &obj);
    ClapTrap(std::string name);
    ClapTrap& operator=(const ClapTrap &obj);
    

};

#endif
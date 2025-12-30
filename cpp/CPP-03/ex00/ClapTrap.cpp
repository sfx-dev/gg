#include "ClapTrap.hpp"



ClapTrap::ClapTrap()
{
    _name = "default";
    _hitPoint = 10;
    _energyPoint = 10;
    _attackDamage = 0; 
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitPoint = 10;
    _energyPoint = 10;
    _attackDamage = 0; 
    std::cout << "ClapTrap parameter constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &obj)
{
    *this = obj; 
    std::cout << "ClapTrap copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap "  << _name  << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap copy assignment called" << std::endl; 
    if(this != &obj)
    {
        this->_attackDamage = obj._attackDamage;
        this->_name = obj._name;
        this->_hitPoint = obj._hitPoint;
        this->_energyPoint = obj._energyPoint;
    }
    return *this;
}


void ClapTrap::attack(const std::string& target)
{
    if(_energyPoint == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack" << std::endl;
        return;
    }
    if(_hitPoint == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of Hit Points and cannot attack" << std::endl;
        return;
    }
    _energyPoint--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount > _hitPoint)
        _hitPoint = 0;
    else
        _hitPoint -= amount;
    std::cout << "ClapTrap " << _name << " take " << amount << " point of damage" << std::endl;

}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(_energyPoint == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot repair" << std::endl;
        return;
    }
    if(_hitPoint == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of Hit Points and cannot repair" << std::endl;
        return;
    }
    _energyPoint--;
    _hitPoint += amount;
    std::cout << "ClapTrap " << _name << "repair his self and he got " << amount << "hit points" << std::endl;

}
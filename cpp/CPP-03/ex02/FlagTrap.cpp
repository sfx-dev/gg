#include "FlagTrap.hpp"


FlagTrap::FlagTrap()
{
    std::cout << "FlagTrap Default Constructor called" << std::endl;
    _name = "default_FlagTrap";
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30; 
}
FlagTrap::~FlagTrap()
{
    std::cout << "FlagTrap " << _name << " destructor called" << std::endl;
}
FlagTrap::FlagTrap(const FlagTrap &obj):ClapTrap(obj)
{
    std::cout << "FlagTrap copy constructor called" << std::endl;
    *this = obj;
}
FlagTrap::FlagTrap(std::string name) :ClapTrap(name)
{
    std::cout << "FlagTrap parameter constructor called" << std::endl;
    _name = name;
    _attackDamage = 30;
    _hitPoint = 100;
    _energyPoint = 100;
}
FlagTrap& FlagTrap::operator=(const FlagTrap& obj)
{
    if(this != &obj)
    {
        std::cout << "FlagTrap copy assignment called" << std::endl; 
        if(this != &obj)
        {
            this->_attackDamage = obj._attackDamage;
            this->_name = obj._name;
            this->_hitPoint = obj._hitPoint;
            this->_energyPoint = obj._energyPoint;
        }
        return *this;
    }
}
void FlagTrap::attack(const std::string& target)
{
    if(_energyPoint == 0)
    {
        std::cout << "FlagTrap " << _name << " is out of energy and cannot attack" << std::endl;
        return;
    }
    if(_hitPoint == 0)
    {
        std::cout << "FlagTrap " << _name << " is out of Hit Points and cannot attack" << std::endl;
        return;
    }
    _energyPoint--;
    std::cout << "FlagTrap " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage" << std::endl;
}

void FlagTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap " << _name << " request a high five" << std::endl;
}

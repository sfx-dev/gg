#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    _name = "default_ScavTrap";
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20; 
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &obj):ClapTrap(obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = obj;
}
ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
    std::cout << "ScavTrap parameter constructor called" << std::endl;
    _name = name;
    _attackDamage = 20;
    _hitPoint = 100;
    _energyPoint = 50;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if(this != &obj)
    {
        std::cout << "ScavTrap copy assignment called" << std::endl; 
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
void ScavTrap::attack(const std::string& target)
{
    if(_energyPoint == 0)
    {
        std::cout << "ScavTrap " << _name << " is out of energy and cannot attack" << std::endl;
        return;
    }
    if(_hitPoint == 0)
    {
        std::cout << "ScavTrap " << _name << " is out of Hit Points and cannot attack" << std::endl;
        return;
    }
    _energyPoint--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is  in Gate keeper mode." << std::endl;
}


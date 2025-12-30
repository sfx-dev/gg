#include "Zombie.hpp"


Zombie::Zombie()
{
}

void Zombie::announce()
{
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;  
}

void Zombie::setName(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << _name << " destroyed" << std::endl;
}
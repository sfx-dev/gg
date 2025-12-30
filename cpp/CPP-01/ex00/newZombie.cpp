#include "Zombie.hpp"


Zombie* newZombie(std::string name)
{
    Zombie *ptr = new(std::nothrow) Zombie(name);
    if(!ptr)
        return NULL;
    return ptr;
}

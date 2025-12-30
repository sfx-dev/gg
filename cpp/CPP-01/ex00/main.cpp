#include "Zombie.hpp"


int main()
{
    Zombie *ptr  = newZombie("sfx");
    ptr->announce();
    delete ptr;
    
    randomChump("obajali");
}
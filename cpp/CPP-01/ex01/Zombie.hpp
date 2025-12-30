#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>




class Zombie{
    
    private:
    std::string _name;
    
    public:
    void announce();
    void setName(std::string name);
    Zombie();
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
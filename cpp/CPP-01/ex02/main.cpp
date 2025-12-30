
#include <string>
#include <iostream>

int main()
{
    std::string x = "HI THIS IS BRAIN";
    std::string *stringPTR = &x;
    std::string &stringREF = x;

    std::cout << &x << std::endl;
    std::cout << &stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    
}
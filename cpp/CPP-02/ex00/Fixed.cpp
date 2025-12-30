#include "Fixed.hpp"


const int Fixed::scale = 8;


int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed& Fixed::operator=(const Fixed  &object)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &object)
        this->value = object.getRawBits();
    return *this;
}


Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}
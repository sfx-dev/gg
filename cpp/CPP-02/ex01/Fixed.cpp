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
        this->value = object.value;
    return *this;
}

std::ostream& operator<<(std::ostream &output, const Fixed &object)
{
    output << object.toFloat();
    return output;
}
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}
Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    value = x << scale;
}
Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    value = (int)roundf(x * (1 << scale));
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

float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->value) / static_cast<float>(1 << this->scale);
}

int Fixed::toInt(void) const
{
    return value >> this->scale;
}
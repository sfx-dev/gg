#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed{

private:
    int value;
    static const int scale;

public:
    Fixed(); 
    Fixed(const Fixed &obj);
    Fixed(const int x);
    Fixed(const float x);
    ~Fixed();
    Fixed& operator=(const Fixed &object);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;
    
};

std::ostream& operator<<(std::ostream &output, const Fixed &object);


#endif
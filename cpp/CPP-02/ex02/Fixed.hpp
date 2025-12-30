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
    
    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;


    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--(); 
    Fixed operator--(int);


    
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
    
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;
    
};

std::ostream& operator<<(std::ostream &output, const Fixed &object);


#endif
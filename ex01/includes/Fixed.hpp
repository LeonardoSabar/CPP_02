#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &fixed);
        ~Fixed();
        Fixed &operator=(const Fixed &fixed);

        Fixed(const int integer);
        Fixed(const float floatingPoint);

        float toFloat() const;
        int toInt() const;

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
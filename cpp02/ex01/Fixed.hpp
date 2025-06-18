#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
    static const int fractBits = 8;
    int fixedPoint;

public:
    int getRawBits(void) const;
    void setRawBits(int const raw) const;

    float toFloat() const;
    int toInt() const;

    Fixed();
    Fixed(int const val);
    Fixed(float const val);
    Fixed(Fixed const &other);

    ~Fixed();

    Fixed &operator=(Fixed const &other);
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
    static const int fractBits = 8;
    int rawBits;

public:
    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;

    Fixed();
    Fixed(int const val);
    Fixed(float const val);
    Fixed(Fixed const &other);

    ~Fixed();

    Fixed &operator=(Fixed const &other);
};
std::ostream& operator<<(std::ostream& os, const Fixed& other);


#endif
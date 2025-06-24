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

    float toFloat() const;
    int toInt() const;

    static Fixed& min(Fixed& fst, Fixed& scnd); // working
    static Fixed& max(Fixed& fst, Fixed& scnd); // working

    static const Fixed& min(const Fixed& fst, const Fixed& scnd); // working
    static const Fixed& max(const Fixed& fst, const Fixed& scnd); // working

    // Operations operators
    Fixed operator++( void ); // working
    Fixed operator++( int ); // working
    Fixed operator--( void ); // working
    Fixed operator--( int ); // working
    Fixed operator+(const Fixed& other); // working
    Fixed operator-(const Fixed& other); // working
    Fixed operator*(const Fixed& other); // working
    Fixed operator/(const Fixed& other); // working

    // Comparison operators
    bool operator==(const Fixed& other);  // working
    bool operator!=(const Fixed& other);  // working
    bool operator<(const Fixed& other);  // working
    bool operator>(const Fixed& other);  // working
    bool operator<=(const Fixed& other);  // working
    bool operator>=(const Fixed& other);  // working

    // Print operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fst);

    Fixed();
    Fixed(int const val);
    Fixed(float const val);
    Fixed(Fixed const &other);

    ~Fixed();

    Fixed &operator=(Fixed const &other);
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif
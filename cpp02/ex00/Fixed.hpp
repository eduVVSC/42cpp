#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
    static const int fractBits = 8;
    int raw;

public:
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed();
    Fixed(Fixed const &other);

    ~Fixed();

    Fixed &operator=(Fixed const &other);
};

#endif
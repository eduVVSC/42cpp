//
// Created by edvieira on 6/16/25.
//

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed {
private:
    static const int fractBits = 8;

    int fixedPoint;

public:
    int getRawBits(void) const;
    void setRawBits(int const raw) const;

    Fixed();
    Fixed(Fixed const &other);

    ~Fixed();

    Fixed &operator=(Fixed const &other);
};

#endif //FIXED_H

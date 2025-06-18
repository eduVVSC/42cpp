#include "Fixed.hpp"


int Fixed::getRawBits() const {
    std::cout << "getRawBits() member function called" << std::endl;
    return fixedPoint;
}

void Fixed::setRawBits(int const raw) const {
    (void) raw;
}


// ======== constructor and destructor

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedPoint = 0;
}

Fixed::Fixed(Fixed const &other) {
    std::cout << "Copy constructor operator called" << std::endl;
    this->fixedPoint = other.getRawBits();
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPoint = other.getRawBits();
    return *this;
}


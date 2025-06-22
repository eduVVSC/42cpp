#include "Fixed.hpp"

int Fixed::getRawBits() const {
    std::cout << "getRawBits() member function called" << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

int Fixed::toInt() const {

}

float Fixed::toFloat() const {

}

// ======== constructor and destructor

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(float const val) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int const val) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
    std::cout << "Copy constructor operator called" << std::endl;
    this->rawBits = other.getRawBits();
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ======== operators

Fixed &Fixed::operator=(Fixed const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawBits = other.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
}
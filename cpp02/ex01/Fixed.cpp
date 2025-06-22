#include "Fixed.hpp"

int Fixed::getRawBits() const {
    //std::cout << "getRawBits() member function called" << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

int Fixed::toInt() const {
    int integerPart = this->rawBits >> this->fractBits;
    return integerPart;
}

float Fixed::toFloat() const {
    return ((float)rawBits / (1 << fractBits));
}

// ======== constructor and destructor

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(float const val) {
    std::cout << "Float constructor called" << std::endl;
    int intPart = (int) val;
    float floatPart = val - intPart;

    this->rawBits = intPart << 8;
    this->rawBits += (int) (floatPart * (1 << fractBits));
}

Fixed::Fixed(int const val) {
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = val << 8;
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
    os << other.toFloat();
    return os;
}
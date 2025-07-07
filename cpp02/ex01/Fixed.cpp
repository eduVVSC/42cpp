/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 10:46:45 by edvieira          #+#    #+#             */
/*   Updated: 2025-07-07 10:46:45 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits() const {
    //std::cout << "getRawBits() member function called" << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

int Fixed::toInt( void ) const {
    float intInFloat = toFloat();
    return ((int) roundf(intInFloat));
}

float Fixed::toFloat( void ) const {
    return ((float)rawBits / (1 << fractBits));
}

// ======== constructor and destructor

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(float const val) {
    std::cout << "Float constructor called" << std::endl;
    float floatPart = roundf(val * (1 << fractBits));  
    
    this->rawBits = (int) floatPart;
}

Fixed::Fixed(int const val) {
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = val << 8;
}

Fixed::Fixed(Fixed const &other) {
    std::cout << "Copy constructor operator called" << std::endl;
    *this = other;
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
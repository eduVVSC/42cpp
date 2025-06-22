#include "Fixed.hpp"

// ======= Operators
bool Fixed::operator==(const Fixed& other){
  return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed& other){
	return rawBits != other.rawBits;
}

bool Fixed::operator<(const Fixed& other){
  if(this->toFloat() < other.toFloat()){
    return true;
  }
  return false;
}

bool Fixed::operator>(const Fixed& other){
  if(this->toFloat() > other.toFloat()){
    return true;
  }
  return false;
}

bool Fixed::operator<=(const Fixed& other){
  if(this->toFloat() <= other.toFloat()){
    return true;
  }
  return false;
}

bool Fixed::operator>=(const Fixed& other){
  if(this->toFloat() >= other.toFloat()){
    return true;
  }
  return false;
}

Fixed Fixed::operator++( void ){
	rawBits = rawBits + 1;
	return *this;
}

Fixed Fixed::operator++( int ){
  Fixed temp = *this;  // make a copy
  rawBits = rawBits + 1;
  return temp;
}

Fixed Fixed::operator--( void ){
	rawBits = rawBits - 1;
	return *this;
}

Fixed Fixed::operator--( int ){
  Fixed temp = *this;  // make a copy
  rawBits = rawBits - 1;
  return temp;
}

Fixed Fixed::operator+(const Fixed& other){
  	Fixed result(0);
    result.setRawBits(rawBits + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other){
	Fixed result(0);
    result.setRawBits(rawBits - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other){
	Fixed result(0);

   	result.setRawBits((rawBits * other.getRawBits()) >> fractBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other){
	Fixed result(0);
   	result.setRawBits((this->rawBits << fractBits) / other.getRawBits());
    return result;
}


// ======= Comparision

Fixed& Fixed::min(Fixed& fst, Fixed& scnd){
  if(fst.toFloat() < scnd.toFloat()){
    return fst;
  }
  return scnd;
}


Fixed& Fixed::max(Fixed& fst, Fixed& scnd){
	if(fst.toFloat() > scnd.toFloat()){
       	return fst;
	}
    return scnd;
}


const Fixed& Fixed::min(const Fixed& fst, const Fixed& scnd){
  if(fst.toFloat() < scnd.toFloat())
    return fst;
  return scnd;
}


const Fixed& Fixed::max(const Fixed& fst, const Fixed& scnd){
  if(fst.toFloat() > scnd.toFloat())
    return fst;
  return scnd;
}

// ======= Functions

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
    //std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(float const val) {
    //std::cout << "Float constructor called" << std::endl;
    int intPart = (int) val;
    float floatPart = val - intPart;

    this->rawBits = intPart << 8;
    this->rawBits += (int) (floatPart * (1 << fractBits));
}

Fixed::Fixed(int const val) {
    //std::cout << "Int constructor called" << std::endl;
    this->rawBits = val << 8;
}

Fixed::Fixed(Fixed const &other) {
    //std::cout << "Copy constructor operator called" << std::endl;
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
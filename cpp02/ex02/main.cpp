#include <iostream>
#include "Fixed.hpp"



void tests() {
  Fixed a(2);
  Fixed *b = new Fixed(10);
  std::cout << "a is : " << a << std::endl;
  std::cout << "b is : " << *b << std::endl;

  std::cout << "\n============ Testing Comparisons ============"<< std::endl;
  std::cout << Fixed::max(a,*b) << std::endl;
  std::cout << Fixed::min(a,*b) << std::endl;
  std::cout << "(a < *b) => " << (a < *b) << std::endl;
  std::cout << "(a <= *b) => " << (a <= *b) << std::endl;
  std::cout << "(a > *b) => " << (a > *b) << std::endl;
  std::cout << "(a >= *b) => " << (a >= *b) << std::endl;
  std::cout << "(a == *b) => " << (a == *b) << std::endl;

  std::cout << "\n============ Testing Operations ============"<< std::endl;
  std::cout << "(a + *b) => " << (a + *b) << std::endl;
  std::cout << "(a - *b) => " << (a - *b) << std::endl;
  std::cout << "(++a)" << std::endl;
  std::cout << "before => " << a << " - " << a.getRawBits() << "\nafter =>  " << ++a << " - " << a.getRawBits() << std::endl;
  std::cout << "(--a)" << std::endl;
  std::cout << "before => " << a << " - " << a.getRawBits() << "\nafter =>  " << --a << " - " << a.getRawBits() << std::endl;
  std::cout << "(a * *b) => " << (a * *b) << std::endl;
  std::cout << "(a / *b) => " << (a / *b) << std::endl;
  std::cout << "(*b / a) => " << (*b / a) << std::endl;
  delete b;
}

int main( void ) {
  // tests in the subject
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  return 0;
}
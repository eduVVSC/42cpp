/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 10:47:30 by edvieira          #+#    #+#             */
/*   Updated: 2025-07-07 10:47:30 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

void tests() {
  std::cout << "\n Other tests\n" << std::endl;
  Fixed a(2);
  Fixed *b = new Fixed(10);
  Fixed c = a * *b;

  std::cout << "a is : " << a << std::endl;
  std::cout << "b is : " << *b << std::endl;
  std::cout << "c(a * b) is : " << c << std::endl;

  std::cout << "\n============ Testing Comparisons ============"<< std::endl;
  std::cout << "a is : " << a << " b is : " << *b << std::endl;
  std::cout << "max is = " << Fixed::max(a,*b) << std::endl;
  std::cout << "min is = " << Fixed::min(a,*b) << std::endl;
  std::cout << "(a < *b) => " << (a < *b) << std::endl;
  std::cout << "(a <= *b) => " << (a <= *b) << std::endl;
  std::cout << "(a > *b) => " << (a > *b) << std::endl;
  std::cout << "(a >= *b) => " << (a >= *b) << std::endl;
  std::cout << "(a == *b) => " << (a == *b) << std::endl;

  std::cout << "\n============ Testing Operations ============"<< std::endl;
  std::cout << "(a + *b) => " << (a + *b) << std::endl;
  std::cout << "(a - *b) => " << (a - *b) << std::endl;
  std::cout << "\n(++a)" << std::endl;
  std::cout << "before => " << a << " - " << a.getRawBits() << "\nafter =>  " << ++a << " - " << a.getRawBits() << std::endl;
  std::cout << "(a++)" << std::endl;
  std::cout << "before => " << a << " - " << a.getRawBits() << "\nafter =>  " << a++ << " - " << a.getRawBits() << std::endl;
  std::cout << "next line a value is => " << a << std::endl;

  std::cout << "\n(--a)" << std::endl;
  std::cout << "before => " << a << " - " << a.getRawBits() << "\nafter =>  " << --a << " - " << a.getRawBits() << std::endl;
  std::cout << "(a--)" << std::endl;
  std::cout << "before => " << a << " - " << a.getRawBits() << "\nafter =>  " << a-- << " - " << a.getRawBits() << std::endl;
  std::cout << "next line a value is => " << a << std::endl;


  std::cout << "\n(a * *b) => " << (a * *b) << std::endl;
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
  // extra tests
  //tests();
  return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 10:46:50 by edvieira          #+#    #+#             */
/*   Updated: 2025-07-07 10:46:50 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void){
  Fixed a;
  Fixed b( a );
  Fixed c;


  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  c.setRawBits(2);
  Fixed d = c;
  std::cout << c.getRawBits() << std::endl;
  std::cout << d.getRawBits() << std::endl;
  return 0;
}

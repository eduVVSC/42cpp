/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:05:51 by edvieira          #+#    #+#             */
/*   Updated: 2025/07/14 07:13:52 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void )
{
	int test[5];

	test[0] = 0;
	test[1] = 1;
	test[2] = 2;
	test[3] = 3;
	test[4] = 4;


	char c[5];
	c[0] = '0';
	c[1] = '1';
	c[2] = '2';
	c[3] = '3';
	c[4] = '4';

	try
	{
		// will work perfectly!
		int returned = easyfind(test, 3);
		std::cout << "value returned = " << returned << std::endl;

		// will throw and exception because the type sent is not a int!
		returned = easyfind(c, 3);
		std::cout << "value returned = " << returned << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

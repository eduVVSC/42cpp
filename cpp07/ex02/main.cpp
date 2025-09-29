/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:03:01 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/29 21:05:35 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

void exceptionTest(Array< int > m)
{
	try {
		std::cout << "Trying to access the memory in position 10 with []" << std::endl;
		m[10];
	}
	catch(const std::exception& e) {
		std::cerr << "\t" << e.what() << '\n';
	}

	try {
		std::cout << "Trying to access the memory in position 10 with getIndexValue(10)" << std::endl;
		m.getIndexValue(10);
	}
	catch(const std::exception& e) {
		std::cerr << "\t" << e.what() << '\n';
	}

}


int main( void )
{
	Array < int > m(5);

	m[0] = 0;	m[1] = 1;	m[2] = 2;	m[3] = 3;	m[4] = 4;

	std::cout << "My Array: " << m << std::endl;
	std::cout << "Size is: " << m.size() << "\n" << std::endl;

	exceptionTest(m);

	std::cout << "\nTesting creating array with copy constructor!" << std::endl;
	Array < int > n (m);
	//Array< int > n = m;
	std::cout << "My Array: " << n << std::endl;
	m[0] = 10;
	m[1] = 11;
	m[2] = 12;
	m[3] = 13;
	m[4] = 14;

	std::cout << "\n -> After aplying changes:" << std::endl;
	std::cout << "m: " << m << std::endl;
	std::cout << "n: " << n << std::endl;

	return (0);
}

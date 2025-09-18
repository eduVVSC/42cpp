/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:00 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/17 14:20:06 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main()
{
	std::cout << "start of program" << std::endl;
	try
	{
		BitcoinExchange bt = BitcoinExchange();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "end of program" << std::endl;
	return 0;
}

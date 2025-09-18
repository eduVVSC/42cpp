/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:00 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/18 10:39:34 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::cout << "start of program" << std::endl;
		try {
			BitcoinExchange bt = BitcoinExchange();
			std::cout << "=============================" << std::endl;
			bt.convert(av[1]);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << " -> in main" << std::endl;
		}
	}
	std::cout << "end of program" << std::endl;

	(void) av;
	return (0);
}

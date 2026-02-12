/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:00 by edvieira          #+#    #+#             */
/*   Updated: 2026/02/12 13:35:31 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try {
			BitcoinExchange bt = BitcoinExchange();
			// std::cout << "=============================" << std::endl;
			bt.convert(av[1]);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << " -> in main" << std::endl;
		}
	}
	(void) av;
	return (0);
}

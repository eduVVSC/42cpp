/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:00 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/19 10:35:47 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN a = RPN();
		try
		{
			//std::cout << "result is: " << a.makeCount("8 9 * 9 - 9 - 9 - 4 - 1 +") << std::endl;

			std::cout << "result is: " << a.makeCount(av[1]) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}

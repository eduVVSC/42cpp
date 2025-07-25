/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:44 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 13:42:25 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std:: cout << " --> Test of stack memory! Going inside randomChump function:\n" << std::endl;
		randomChump("ofStack");
	std::cout << "\n--------back in main!!--------\n" << std::endl;

	std:: cout << " -->  Test of heap memory! Going inside newZombie function:\n" << std::endl;
		Zombie *zb2 = newZombie("ofHeap");
	std::cout << "\n--------back in main!!--------\n" << std::endl;

	zb2->announce();

	delete zb2;
	return (0);
}

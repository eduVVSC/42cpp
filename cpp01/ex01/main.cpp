/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:44 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 17:23:50 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string	name = "daStack";
	int	many = 10;

	Zombie zb(name);
	Zombie *zb2 = zombieHorde(many , "daHeap");

	std::cout << "-locally created: " << std::endl;
	zb.announce();


	std::cout << "\n-Horde Created inside function: " << std::endl;
	for (int i = 0; i < many; i++)
		zb2[i].announce();

	delete [] zb2;
	return (0);
}

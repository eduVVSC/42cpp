/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:44 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/24 16:18:09 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int	many = 10;

	Zombie zb("daStack");
	Zombie *zb2 = zombieHorde(many , "daHeap");

	std::cout << "======Starting announcements======" << std::endl;
	std::cout << "-locally created: " << std::endl;
	zb.announce();

	std::cout << "\n-Horde Created inside function: " << std::endl;
	for (int i = 0; i < many; i++)
		zb2[i].announce();

	delete [] zb2; // to do not give memory leaks
	return (0);
}

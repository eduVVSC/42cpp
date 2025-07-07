/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:44 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 13:54:48 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int	many = 10;
	std::cout << "\n =============== invalid quantity of zombies  ===============" << std::endl;

	Zombie *wrongTest1 = zombieHorde(-1 , "daHeap");
	Zombie *wrongTest2 = zombieHorde(0 , "daHeap");
	(void) wrongTest1;
	(void) wrongTest2;
	std::cout << "\n =============== valid quantity of zombies  ===============" << std::endl;

	Zombie *zbHorde = zombieHorde(many , "daHeap");

	std::cout << "\n =============== announcing in main ===============" << std::endl;
	std::cout << "\n-Horde Created inside function: " << std::endl;
	for (int i = 0; i < many; i++)
		zbHorde[i].announce();

	delete [] zbHorde; // all zombies being deleted at the same time
	return (0);
}

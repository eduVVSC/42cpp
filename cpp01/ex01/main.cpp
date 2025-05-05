/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:44 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 13:54:48 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int	many = 10;

	Zombie *zbHorde = zombieHorde(many , "daHeap");
	std::cout << "\n-------------back in main!!-------------" << std::endl;

	std::cout << "\n-Horde Created inside function: " << std::endl;
	for (int i = 0; i < many; i++)
		zbHorde[i].announce();

	delete [] zbHorde;
	return (0);
}

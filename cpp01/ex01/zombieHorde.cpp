/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:58 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 17:21:47 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{
	std::cout << "\n------------------------------------------\n\tInside newZombie!!\n" << std::endl;
	if (N < 1)
	{
		std::cout << "!!not valid num to create horde!!" << std::endl;
		return (NULL);
	}


	Zombie	*zbArr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zbArr[i].setName(name);
	}

	std::cout << "\n\tgoing back to main!!\n------------------------------------------" << std::endl;
	return (zbArr);
}


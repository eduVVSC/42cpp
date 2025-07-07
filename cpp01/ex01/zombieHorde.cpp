/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:58 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 14:54:14 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	//std::cout << "\n-------------Inside ZmHorde!!-------------\n" << std::endl;
	if (N < 1) {
		std::cout << "!!not valid num to create horde!!" << std::endl;
		return (NULL);
	}

	// alocating [n] values to the pointer
	Zombie	*zbArr = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zbArr[i].setName(name);
	}

	return (zbArr);
}

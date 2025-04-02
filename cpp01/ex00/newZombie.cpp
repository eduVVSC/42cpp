/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:58 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/02 21:31:38 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	std::cout << "\n------------------------------------------\n\tInside newZombie!!\n" << std::endl;


	Zombie *zb = new Zombie(name);
	std::cout << "\n\tgoing back to main!!\n------------------------------------------" << std::endl;
	return (zb);
}


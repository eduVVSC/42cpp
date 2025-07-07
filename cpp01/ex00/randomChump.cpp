/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:12:04 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 13:30:58 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	//std::cout << "\n-----------------------Inside randomChump!!-----------------------\n" << std::endl;

	Zombie zb(name);
	zb.announce();

	//std::cout << "\n-----------------------going back to main-----------------------" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:12:04 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 16:14:51 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	//std::cout << "\n------------------------------------------\n\tInside randomChump!!\n" << std::endl;

	Zombie zb(name);
	zb.announce();

	//std::cout << "\n\tgoing back to main!!\n------------------------------------------" << std::endl;
}

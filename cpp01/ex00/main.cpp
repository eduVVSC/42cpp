/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:44 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 16:17:33 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string name = "daStack";
	Zombie zb(NULL);
	Zombie *zb2 = newZombie("daHeap");

	randomChump("chris");

	zb.announce();
	zb2->announce();
	delete zb2;
	return (0);
}

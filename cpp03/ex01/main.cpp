/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:35 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 16:24:39 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap *st1 = new ScavTrap("test");

	st1->guardGate();
	st1->attack("test1");
	st1->beRepaired(10);
	st1->takeDamage(10);
	delete st1;
}

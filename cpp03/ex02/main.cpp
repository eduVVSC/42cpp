/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:35 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 16:51:08 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap *st1 = new FragTrap("test");
	FragTrap *st2 = new FragTrap(*st1);

	st1->highFiveGuys();
	st1->attack("enemy");
	st1->beRepaired(10);
	st1->takeDamage(10);

	delete st1;
	std::cout << "\nnext test\n";
	st2->highFiveGuys();
	st2->attack("enemy");
	st2->beRepaired(10);
	st2->takeDamage(10);
	delete st2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:35 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 16:39:51 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	std::cout << "\n ===== creating first ScavTrap ===== " << std::endl;
	ScavTrap *st1 = new ScavTrap("testScavTrap");

	std::cout << "\n ===== creating Seconf ScavTrap ===== " << std::endl;
	ScavTrap *st2 = new ScavTrap(*st1);

	std::cout << "\n ===== creating Third ScavTrap ===== " << std::endl;
	ClapTrap *t = new ClapTrap("testClap");

	std::cout << "\n ===== tests ===== " << std::endl;
	st1->guardGate();
	st1->attack("enemy");
	st1->beRepaired(10);
	st1->takeDamage(10);

	delete st1;
	std::cout << "\nnext test\n";
	st2->guardGate();
	st2->attack("enemy");
	st2->beRepaired(10);
	st2->takeDamage(10);


	delete st2;
	std::cout << "\nnext test\n";
	t->attack("enemy");
	t->beRepaired(10);
	t->takeDamage(10);

	delete t;
}

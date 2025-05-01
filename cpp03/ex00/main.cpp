/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:35 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/01 17:45:43 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap *cp1 = new ClapTrap("teste1");
	ClapTrap *cp2 = new ClapTrap("teste2");
	ClapTrap *cp3 = new ClapTrap("teste2");


	// test to check if the subtraction of energyPoints is accured
	std::cout << "========test 10 atacks========" << std::endl;
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");
	cp1->attack("target1");

	std::cout << "11th =>  ";
	cp1->attack("target1");


	std::cout << "\n========test 10 repairs========" << std::endl;
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);
	cp2->beRepaired(10);

	std::cout << "11th =>  ";
	cp2->beRepaired(10);

	// will execute because are unsigned int
	std::cout << "\n========test neg values========" << std::endl;
	cp3->takeDamage(-10);
	cp3->beRepaired(-10);
}

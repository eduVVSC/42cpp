/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:09:28 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 09:13:10 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap -> Constructor called for: " << name << std::endl;

	trap = new ClapTrap(name);
	trap->setHitPoints(100);
	trap->setEnergyPoint(50);
	trap->setAttackDamage(20);
}

// check if it is correct in here
ScavTrap::ScavTrap(ScavTrap &cp)
{
	std::cout << "ScavTrap -> Constructor called for: " << cp.trap->getName() << std::endl;

	trap = new ClapTrap(*cp.trap);
	trap->setHitPoints(100);
	trap->setEnergyPoint(50);
	trap->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::string name = this->trap->getName();

	delete trap;

	std::cout << "ScavTrap -> Destructor called for: " << name << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->trap->getName() << " ScavTrap is now in Gate keeper mode." << std::endl;
}

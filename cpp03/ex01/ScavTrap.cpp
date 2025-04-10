/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:09:28 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 16:24:31 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target)
{
	if(energyPoint > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " + this->name + " attacks " + target + ", causing ";
		std::cout << this->attackDamage + " points of damage!" << std::endl;
		energyPoint--;
	}
	else
		std::cout << "ScavTrap " + this->name + " could not attack because it doesn't have energyPoints or hitPoints" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "ScavTrap " << name << " was attacked, it received " << amount << " hit points." << std::endl;
	//std::cout << "Remaining live: " << hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (energyPoint > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name <<" repairs itself, it regains " << amount << " hit points." << std::endl;
		this->hitPoints += amount;
		energyPoint--;
	}
	else
		std::cout << "ScavTrap " + this->name + " could not repair because it doesn't have energyPoints or hitPoints" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoint = 50;
	attackDamage = 20;
}

// check if it is correct in here
ScavTrap::ScavTrap(ScavTrap &cp) : ClapTrap(cp) { }

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap -> Destructor called for: " << name << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << name << " ScavTrap is now in Gate keeper mode." << std::endl;
}

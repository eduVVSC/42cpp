/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:40:16 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 16:51:38 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFiveGuys(void)
{
	std::cout << "Is there anyone here to high five me?" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if(energyPoint > 0 && hitPoints > 0)
	{
		std::cout << "FragTrap " + this->name + " attacks " + target + ", causing ";
		std::cout << this->attackDamage + " points of damage!" << std::endl;
		energyPoint--;
	}
	else
		std::cout << "FragTrap " + this->name + " could not attack because it doesn't have energyPoints or hitPoints" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "FragTrap " << name << " was attacked, it received " << amount << " hit points." << std::endl;
	//std::cout << "Remaining live: " << hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (energyPoint > 0 && hitPoints > 0)
	{
		std::cout << "FragTrap " << name <<" repairs itself, it regains " << amount << " hit points." << std::endl;
		this->hitPoints += amount;
		energyPoint--;
	}
	else
		std::cout << "FragTrap " + this->name + " could not repair because it doesn't have energyPoints or hitPoints" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap -> Constructor called for: " << name << std::endl;
	hitPoints = 100;
	energyPoint = 100;
	attackDamage = 30;
}

// check if it is correct in here
FragTrap::FragTrap(FragTrap &cp) : ClapTrap(cp)
{
	std::cout << "FragTrap -> Constructor called for: " << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap -> Destructor called for: " << name << std::endl;
}



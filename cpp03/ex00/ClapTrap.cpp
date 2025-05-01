/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:58 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/01 18:19:05 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if(energyPoint > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " + this->name + " attacks " + target + ", causing ";
		std::cout << this->attackDamage + " points of damage!" << std::endl;
		energyPoint--;
	}
	else
		std::cout << "ClapTrap " + this->name + " could not attack because it doesn't have energyPoints or hitPoints" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << name << " was attacked, it received " << amount << " hit points." << std::endl;
	//std::cout << "Remaining live: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name <<" repairs itself, it regains " << amount << " hit points." << std::endl;
		this->hitPoints += amount;
		energyPoint--;
	}
	else
		std::cout << "ClapTrap " + this->name + " could not repair because it doesn't have energyPoints or hitPoints" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;

	std::cout << "Constructor has been called for " + this->name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &cp)
{
	this->name = cp.name;
	this->hitPoints = cp.hitPoints;
	this->energyPoint = cp.energyPoint;
	this->attackDamage = cp.attackDamage;

	std::cout << "Constructor has been called for " + this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called for " + this->name << std::endl;
}

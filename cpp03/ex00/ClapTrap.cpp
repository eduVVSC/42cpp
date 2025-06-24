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
	std::cout << "Constructor has been called for " + name << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &cp)
{
	std::cout << "Copy constructors called" << std::endl;
	*this = cp;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor has been called for " + this->name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const& other) {
	std::cout << "Equal operator called" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoint = other.energyPoint;
	this->attackDamage = other.attackDamage;
	return *this;
}

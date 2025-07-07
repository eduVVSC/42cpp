/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:58 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 16:13:38 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if(energyPoint > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing ";
		std::cout << this->attackDamage << " points of damage!" << std::endl;
		energyPoint--;
	}
	else
		std::cout << "ClapTrap " << this->name << " could not attack because it doesn't have energyPoints or hitPoints" << std::endl;
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
		std::cout << "ClapTrap " << name << " repairs itself, it regains " << amount << " hit points." << std::endl;
		this->hitPoints += amount;
		energyPoint--;
	}
	else
		std::cout << "ClapTrap " << this->name << " could not repair because it doesn't have energyPoints or hitPoints" << std::endl;
}

std::string ClapTrap::getName() { return (this->name); }

int ClapTrap::getHitPoints() { return (this->hitPoints); }

int ClapTrap::getEnergyPoint() { return (this->energyPoint); }

int ClapTrap::getAttackDamage() { return (this->attackDamage); }

void ClapTrap::setHitPoints(int hitPoints){
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoint(int energyPoint){
	this->energyPoint = energyPoint;
}

void ClapTrap::setAttackDamage(int attackDamage){
	this->attackDamage = attackDamage;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
	std::cout << " ClapTrap -> Constructor has been called for: " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &cp)
{
	*this = cp;
	std::cout << " ClapTrap -> Copy Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << " ClapTrap -> destructor has been called for: " << this->name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const& other) {
	std::cout << " ClapTrap ->Equal operator called" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoint = other.energyPoint;
	this->attackDamage = other.attackDamage;
	return *this;
}

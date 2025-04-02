/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:20 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/02 23:04:25 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
	if (!wp)
		std::cout << name << "has no weapon, cannot attack" << std::endl;
	else
		std::cout << name << "attacks with their" << wp->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon wp)
{
	this->wp = &wp;
}

HumanB::HumanB(std::string name, Weapon wp)
{
	this->name = name;
	this->wp = &wp;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->wp = NULL;
}

HumanB::~HumanB()
{

}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:41 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/02 23:04:29 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << name << "attacks with their" << wp->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon wp)
{
	this->wp = &wp;
}
HumanA::HumanA(std::string name, Weapon wp)
{
	this->name = name;
	this->wp = &wp;
}

HumanA::~HumanA()
{
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:41 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 15:08:23 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << (std::string)(wp.getType()) << std::endl;
}

void	HumanA::setWeapon(Weapon &wp)
{
	this->wp = wp;
}

HumanA::HumanA(std::string name, Weapon &wp) : name(name), wp(wp) { }

HumanA::HumanA(Weapon &wp) : name("not declared"), wp(wp) { }

HumanA::~HumanA() { }

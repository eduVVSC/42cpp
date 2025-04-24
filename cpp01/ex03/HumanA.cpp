/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:41 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/24 19:48:27 by edvieira         ###   ########.fr       */
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

HumanA::HumanA(const HumanA &copy) : name(copy.name), wp(copy.wp) { }

HumanA::HumanA(Weapon &wp) : name("not declared"), wp(wp) { }

HumanA::~HumanA() { }

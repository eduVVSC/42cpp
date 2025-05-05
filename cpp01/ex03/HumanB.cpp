/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:20 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 15:10:24 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack() {
	if (!hasWeapon)
		std::cout << name << " has no weapon, cannot attack" << std::endl;
	else
		std::cout << name << " attacks with their " << (this->wp->getType()) << std::endl;
}

void	HumanB::setWeapon(Weapon &wp) {
	this->wp = &wp;
	hasWeapon = true;
}

HumanB::HumanB(std::string name) {
	this->name = name;
	this->wp = NULL;
}

HumanB::HumanB() {
	this->name = "not declared";
	this->wp = NULL;
}

HumanB::~HumanB( ) { }


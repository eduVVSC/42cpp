/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:28 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/24 19:53:38 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void			Weapon::setType(std::string type)
{
	this->type = type;
}

std::string		Weapon::getType(){ return (type); }

Weapon &Weapon::operator=(const Weapon &other)
{
	this->type = other.type;
	return (*this);
}

Weapon::Weapon(const Weapon& cp)
{
	this->type = cp.type;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{
	type = "Not Declared";
}

Weapon::~Weapon()
{

}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:28 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 13:59:48 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void			Weapon::setType(std::string type)
{
	this->type = type;
}

std::string	const &Weapon::getType() const { return (type); }

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


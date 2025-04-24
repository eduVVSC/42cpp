/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:42 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/24 15:24:46 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::getName( void ){ return (name); }

void Zombie::announce( void ) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

Zombie::Zombie(std::string name)
{
	this->name = name;

	//std::cout  << name <<  "- Zombie CREATED" << std::endl;
}

Zombie::Zombie(const Zombie& copy)
{
	this->name = copy.name;

	//std::cout  << name <<  "- Zombie CREATED" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "💀 Destroyer zombie ->" << name << std::endl;
}


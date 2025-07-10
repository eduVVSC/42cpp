/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:47 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:01:56 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

std::string AAnimal::getType() const
{
	return (this->type);
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
	this->brain = new Brain();
	std::cout << "Creating some animal" << std::endl;
}

AAnimal::AAnimal(AAnimal &other)
{
	this->type = other.getType();
	// missing 
}

AAnimal::~AAnimal()
{
	std::cout << "Destroying some animal" << std::endl;
	if (brain)
		delete brain;
}

AAnimal &AAnimal::operator=(const AAnimal &other){
	this->type = other.getType();
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:47 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 11:48:47 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"!

void Animal::makeSound() const
{
	std::cout << "I do not know what sound do i make?!?!?!?" << std::endl;
}
std::string Animal::getType() const
{
	return (this->type);
}

Animal::Animal()
{
	this->type = "I do not know what the fuck i am?!?!?!?";
}

Animal::Animal(Animal &other)
{
	this->type = other.getType();
}

Animal::~Animal()
{
}

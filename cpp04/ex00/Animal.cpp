/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:47 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:13:01 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

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
	std::cout << "Animal Copy constructor" << std::endl;
	this->type = "I do not know what the fuck i am?!?!?!?";
}

Animal::Animal(Animal &other)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal destroyer" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
	this->type = other.getType();
	return (*this);
}

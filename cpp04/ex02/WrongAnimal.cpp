/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:47 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:13:01 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong: I do not know what sound do i make?!?!?!?" << std::endl;
}
std::string WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal::WrongAnimal()
{
	this->type = "I do not know what the fuck i am?!?!?!?";
	std::cout << "Creating some animal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	this->type = other.getType();
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destroying WrongAnimal!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	this->type = other.getType();
	return (*this);
}

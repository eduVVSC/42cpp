/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:47 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:51:24 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Bark Bark Bark!" << std::endl;
}

Brain *Dog::getBrain(){ return (this->brain); }

Dog::Dog(Dog &dog) : Animal()
{
	this->brain = dog.getBrain();
	this->type = dog.getType();
	std::cout << "creating dog!" << std::endl;
}

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "creating dog!" << std::endl;
}

Dog::~Dog()
{
}

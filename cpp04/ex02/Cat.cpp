/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:47 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:51:01 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const {
	std::cout << "Meow!!" << std::endl;
}

Brain *Cat::getBrain(){ return (this->brain); }

Cat::Cat(const Cat &cp) : AAnimal (cp.type) {
	*this = cp;
	std::cout << "Copying cat!" << std::endl;
}

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "creating cat!" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	*this->brain = *other.brain;
	this->type = other.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destroying some cat" << std::endl;
}

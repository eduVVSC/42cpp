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

Cat::Cat(Cat &cp) : Animal (){
	this->brain = cp.getBrain();
	this->type = cp.getType();
	std::cout << "Copying cat!" << std::endl;
}

Cat::Cat() : Animal()
{
	this->brain = new Brain();
	this->type = "cat";
	std::cout << "creating cat!" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	this->type = other.getType();
	return (*this);
}

Cat::~Cat(){
}

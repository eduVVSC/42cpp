/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:47 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 14:57:42 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const {
	std::cout << "Meow!!" << std::endl;
}

Cat::Cat(Cat &cp) : Animal (){
	this->type = cp.getType();
	std::cout << "Copying cat!" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	this->type = other.getType();
	return (*this);
}

Cat::Cat() : Animal()
{
	this->type = "cat";
	std::cout << "creating cat!" << std::endl;
}

Cat::~Cat()
{
}

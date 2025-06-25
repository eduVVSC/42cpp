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

#include "WrongCat.hpp"

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow!!" << std::endl;
}

WrongCat::WrongCat(WrongCat &cp) : WrongAnimal() {
	this->type = cp.getType();
	std::cout << "Copying WrongCat!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	this->type = other.getType();
	return (*this);
}

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "creating WrongCat!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destroying WrongCat!" << std::endl;
}

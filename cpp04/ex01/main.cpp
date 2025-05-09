/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:07 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:52:29 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << "---------------------------------------" << std::endl;

	Animal *a4[4];
	a4[0] = new Dog();
	a4[1] = new Cat();
	a4[2] = new Dog();
	a4[3] = new Cat();
	std::cout << std::endl;

	for (size_t i = 0; i < 4; i++)
		a4[i]->makeSound();

	std::cout << "---------------------------------------" << std::endl;

	for (size_t i = 0; i < 4; i++)
		delete a4[i];
	return (1);
}


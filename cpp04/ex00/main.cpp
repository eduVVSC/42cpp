/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:07 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/01 18:51:30 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

// Search what does the virtual method do differently

int	main(void)
{
	const Animal *a = new Dog();

	std::cout << a->getType() << std::endl;
	a->makeSound();

	const Animal *b = new Animal();

	std::cout << b->getType() << std::endl;
	b->makeSound();
}

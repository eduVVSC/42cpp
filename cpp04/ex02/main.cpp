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

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	//AAnimal a= new AAnimal("sadads"); // will give compilation error, as expected
	std::cout << "\n------------- Constructing -------------" << std::endl;

	Cat *a1 = new Cat();
	Dog *a2 = new Dog();

	std::cout << "\n------------- Making sound -------------" << std::endl;
	std::cout << std::endl;

	a1->makeSound();
	a2->makeSound();

	std::cout << "\n------------- Destroying -------------" << std::endl;
	std::cout << std::endl;

	delete a1;
	delete a2;

	return (1);
}


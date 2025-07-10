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
	std::cout << "\n------------- Constructing -------------" << std::endl;

	Dog *a1 = new Dog();

	a1->getBrain()->addIdea("Idea1");
	a1->getBrain()->addIdea("Idea2");
	a1->getBrain()->addIdea("Idea3");

	std::cout << std::endl;

	Dog *a2 = new Dog(*a1);


	std::cout << "\n------------- Making sound -------------" << std::endl;
	std::cout << std::endl;

	a1->makeSound();
	a2->makeSound();

	std::cout << "\n------------- Adding things to brain -------------" << std::endl;
	std::cout << std::endl;

	//for (int i = 0; i < 100; i++) {
	//	a1->getBrain()->addIdea("a");
	//}

	a1->getBrain()->addIdea("Idea4");
	a1->getBrain()->addIdea("Idea5");
	a1->getBrain()->addIdea("Idea6");

	std::cout << "\n----- checking if both brains have different ideas!" << std::endl;

	a1->getBrain()->displayIdeas();
	a2->getBrain()->displayIdeas();

	std::cout << "\n------------- Destroying -------------" << std::endl;
	std::cout << std::endl;

	delete a1;
	delete a2;

	std::cout << "\n------------- Equal assignment -------------" << std::endl;
	Dog a;
	Dog b = a;
	std::cout << "\n------------- Destroying -------------" << std::endl;

	return (0);
}


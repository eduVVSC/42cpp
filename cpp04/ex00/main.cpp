/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:07 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:15:05 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/* int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
return 0;
} */


int	main(void)
{
	const Animal *a = new Dog();
	std::cout << a->getType() << std::endl;
	a->makeSound();

	std::cout << "---------------------------------------" << std::endl;

	const Animal *a2 = new Cat();
	std::cout << a2->getType() << std::endl;
	a2->makeSound();

	std::cout << "---------------------------------------" << std::endl;

	const Animal *b = new Animal();
	std::cout << b->getType() << std::endl;
	b->makeSound();

	std::cout << "---------------------------------------" << std::endl;

	Animal *a4[4];
	a4[0] = new Dog();
	a4[1] = new Cat();
	a4[2] = new Dog();
	a4[3] = new Cat();
	std::cout << std::endl;

	for (size_t i = 0; i < 4; i++)
		a4[i]->makeSound();

	delete a;
	delete a2;
	delete b;
	for (size_t i = 0; i < 4; i++)
		delete a4[i];
	return (1);
}


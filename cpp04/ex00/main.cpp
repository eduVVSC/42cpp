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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/* int	otherTest(void)
{
	std::cout << "\n------------- Constructing -------------" << std::endl;

	//Animal *test = new WrongCat();

	Animal *a4[4];
	a4[0] = new Dog();
	a4[1] = new Cat();
	a4[2] = new Dog();
	a4[3] = new Cat();

	std::cout << "\n------------- Making sound -------------" << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < 4; i++)
		a4[i]->makeSound();

	std::cout << "\n------------- Destroying -------------" << std::endl;
	for (size_t i = 0; i < 4; i++)
		delete a4[i];

	std::cout << "\n------------- WrongAnimals -------------" << std::endl;
	std::cout << "------------- Constructing -------------" << std::endl;

	WrongCat *b1 = new WrongCat();
	WrongAnimal *b2 = new WrongCat();

	std::cout << "\n------------- Making sound -------------" << std::endl;
	b1->makeSound();
	b2->makeSound();

	std::cout << "\n------------- Destroying -------------" << std::endl;
	delete b1;
	delete b2;
	return (0);
} */


 int main() {
	//otherTest();
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* j = new WrongCat();
	const WrongAnimal* i = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

 	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

 	delete meta;
 	delete j;
 	delete i;
	return 0;
}

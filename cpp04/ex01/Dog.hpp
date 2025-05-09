/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:42:51 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;

	public:
		virtual void makeSound() const;
		Brain *getBrain();

		Dog&operator=(Dog const&);

		Dog(Dog &dog);
		Dog();

		~Dog();
};

#endif

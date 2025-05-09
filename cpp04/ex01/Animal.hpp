/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:16:04 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		virtual void makeSound() const;
		std::string getType() const;

		Animal&operator=(const Animal &other);

		Animal(Animal &other);

		Animal();
		virtual ~Animal();
};

#endif

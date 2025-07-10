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

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
#include <iostream>


class Animal
{
protected:
	std::string type;

public:
	virtual void makeSound() const;
	std::string getType() const;

	
	Animal(Animal &other);
	Animal();
	
	virtual ~Animal();
	Animal&operator=(const Animal &other);
};
#endif

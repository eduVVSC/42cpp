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

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"


class AAnimal
{
protected:
	std::string type;
	Brain *brain;

public:
	virtual void makeSound() const = 0;

	std::string getType() const;

	AAnimal&operator=(const AAnimal &other);

	AAnimal(std::string type);
	AAnimal(AAnimal &other);
	virtual ~AAnimal();
};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:13:16 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		void makeSound() const;
		std::string getType() const;

		WrongAnimal();
		WrongAnimal(WrongAnimal &other);

		WrongAnimal	&operator=(const WrongAnimal &other);

		virtual ~WrongAnimal();
};

#endif

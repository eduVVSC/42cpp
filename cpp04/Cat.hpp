/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/01 18:37:56 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat: public Animal
{
	private:

	public:
		void makeSound();

		Cat&operator=(Cat const&);
		Cat(/* args */);
	 	~Cat();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 14:58:10 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:

	public:
		void makeSound() const;

		WrongCat&operator=(const WrongCat &other);

		WrongCat(WrongCat &cp);
		WrongCat();
		~WrongCat();
};

#endif

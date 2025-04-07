/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:40 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 17:54:12 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		std::string getName( void);
		void setName( std::string name );
		void announce( void );

		Zombie(const Zombie& copy);
		Zombie(std:: string);
		Zombie();

		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif

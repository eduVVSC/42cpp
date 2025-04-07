/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:40 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 17:54:43 by edvieira         ###   ########.fr       */
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
		void announce( void );

		Zombie(const Zombie& copy);
		Zombie(std:: string);

		//Zombie& operator=(const Zombie&);
		~Zombie();
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif

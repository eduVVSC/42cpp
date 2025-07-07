/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:52:40 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 13:27:36 by edvieira         ###   ########.fr       */
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

		Zombie(std:: string);

		~Zombie();
};

// program functions
Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:59 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/10 09:20:13 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
		private:
			std::string	name;
			int			hitPoints;
			int			energyPoint;
			int			attackDamage;

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap(std::string name);
		ClapTrap(ClapTrap &cp);
		~ClapTrap();

		ClapTrap&	operator=(ClapTrap const&);
};

#endif

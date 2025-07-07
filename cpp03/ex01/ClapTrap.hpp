/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:55:59 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/01 17:43:00 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		unsigned int			hitPoints;
		unsigned int			energyPoint;
		unsigned int			attackDamage;

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int getHitPoints();
		int getEnergyPoint();
		int getAttackDamage();
		std::string getName();

		void setHitPoints(int hitPoints);
		void setEnergyPoint(int energyPoint);
		void setAttackDamage(int attackDamage);

		ClapTrap(std::string name);
		ClapTrap(ClapTrap &cp);
		~ClapTrap();

		ClapTrap&	operator=(ClapTrap const&);
};

#endif

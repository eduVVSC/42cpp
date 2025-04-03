/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:09 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/03 14:01:48 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string		name;
		Weapon			*wp;
		bool			hasWeapon;
	public:
		void	attack();
		void	setWeapon(Weapon &wp);

		HumanB(std::string name, Weapon &wp);
		HumanB(std::string name);

		~HumanB();
};

#endif

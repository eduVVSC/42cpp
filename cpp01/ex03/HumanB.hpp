/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:09 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 15:07:57 by edvieira         ###   ########.fr       */
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

		HumanB(std::string name);
		HumanB();

		~HumanB();
};

#endif

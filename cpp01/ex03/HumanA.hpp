/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:31 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/02 23:04:13 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"


class HumanA
{
	private:
		std::string		name;
		Weapon			*wp;
	public:
		void	attack();
		void	setWeapon(Weapon wp);


		HumanA(std::string name, Weapon wp);

		~HumanA();
};


#endif

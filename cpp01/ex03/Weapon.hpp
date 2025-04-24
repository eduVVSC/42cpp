/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:29 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/24 19:43:44 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		void		setType(std::string type);
		std::string	getType();

		Weapon(const Weapon& cp);
		Weapon(std::string type);
		Weapon();

		Weapon& operator=(const Weapon&);
		~Weapon();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42porto.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:29 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 14:55:06 by edvieira         ###   ########.fr       */
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
		std::string	const &getType() const;

		Weapon(std::string type);
		Weapon();

		~Weapon();
};

#endif

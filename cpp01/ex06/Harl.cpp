/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:11:19 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 11:21:36 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>
#include <functional>

void Harl::complain( std::string level )
{
	std::string	arrStr[4];
	void (Harl::*arrVoid[4])();

	arrStr[0] = "";
	arrStr[1] = "";
	arrStr[2] = "";
	arrStr[3] = "";

	arrVoid[0] = &Harl::debug;
	arrVoid[1] =  &Harl::info;
	arrVoid[2] =  &Harl::warning;
	arrVoid[3] =  &Harl::error;

	for (int i = 0; i < 4; ++i)
	{
		if (arrStr[i] == level)
		{
			(this->*arrVoid[i])();
			break ;
		}
	}
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month" << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}

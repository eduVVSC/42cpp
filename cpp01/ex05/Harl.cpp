/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:11:19 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 16:24:40 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level )
{
	std::string	arrStr[4];
	void (Harl::*arrVoid[4])();

	// doing the same map should, we are create a type of key array, and one
	// that saves the pointers to the functions that will be used whenever the
	// key entered is trigger to the respective functions

	arrStr[0] = "DEBUG";
	arrStr[1] = "INFO";
	arrStr[2] = "WARNING";
	arrStr[3] = "ERROR";

	arrVoid[0] = &Harl::debug;
	arrVoid[1] =  &Harl::info;
	arrVoid[2] =  &Harl::warning;
	arrVoid[3] =  &Harl::error;

	for (int i = 0; i < 4; ++i)
	{
		if (arrStr[i] == level)
		{
			(this->*arrVoid[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl() { }

Harl::~Harl() { }

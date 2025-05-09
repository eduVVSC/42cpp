/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:11:19 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 14:00:30 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>
#include <functional>

int Harl::getHash(std::string level) {
	if (level == "DEBUG")
		return ComplainType::DEBUG;
	if (level == "INFO")
		return ComplainType::INFO;
	if (level == "WARNING")
		return ComplainType::WARNING;
	if (level == "ERROR")
		return ComplainType::ERROR;
	return ComplainType::NONE;
}

void Harl::complain( std::string level )
{
	/*
		// ====== without  switch ======  //

	bool		printState;
	std::string	arrStr[4];
	void (Harl::*arrVoid[4])();

	arrStr[0] = "DEBUG";
	arrStr[1] = "INFO";
	arrStr[2] = "WARNING";
	arrStr[3] = "ERROR";

	arrVoid[0] = &Harl::debug;
	arrVoid[1] =  &Harl::info;
	arrVoid[2] =  &Harl::warning;
	arrVoid[3] =  &Harl::error;

	printState = false;

	for (int i = 0; i < 4; ++i)
	{
		if (arrStr[i] == level || printState)
		{
			(this->*arrVoid[i])();
			printState = true;
		}
	}
	if (printState == false)
		std::cout << "[ Probably complaning about insignificant problems ]" << std::endl; */

	switch (getHash(level))
	{
		case ComplainType::DEBUG:
			debug();
			info();
			warning();
			error();
			break ;

		case ComplainType::INFO:
			info();
			warning();
			error();
			break ;

		case ComplainType::WARNING:
			warning();
			error();
			break;

		case ComplainType::ERROR:
			error();
			break ;

		default:
			std::cout << "[ Probably complaning about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\ns" << std::endl;
}


Harl::Harl()
{
}

Harl::~Harl()
{
}

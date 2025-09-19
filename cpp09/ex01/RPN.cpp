/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 07:31:26 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/19 08:59:05 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::makeCount(std::string s)
{
	populateQueue(s);

	
	return (1);
}

/// @brief Function will populate the queue with the tokens
/// @param s
/// @throw BadCharactersException
void RPN::populateQueue(std::string s)
{
	int pos;

	while (s.find(' ') != std::string::npos)
	{
		pos = s.find(' ');
		if ((pos - 1) >= 0)
		{
			std::string temp = s.substr(0, pos);

			if (!onlyAllowedCharacter(temp))
				throw BadCharactersException("Unallowed Characters were used in the tokens. Try again!");

			tokens.push(temp);
			//std::cout << "token: " << s.substr(0, pos) << std::endl;
		}
		s.erase(0, pos + 1);
	}
	if (!s.empty())
	{
		tokens.push(s);  // taking the substring of the string until the found ' 's
		//std::cout << "Missing this: " << s << std::endl;
	}
}

/// @brief Function check if the characters in the string are the allowed one(nums and *, -, +, /)
/// @param s
/// @return (true - allowed chars) (false - not allowed chars)
bool RPN::onlyAllowedCharacter(std::string s)
{
	if (s.compare("*") == 0)
		return (true);
	if (s.compare("-") == 0)
		return (true);
	if (s.compare("+") == 0)
		return (true);
	if (s.compare("/") == 0)
		return (true);

	size_t start = 0;
	if (s.at(start) == '-')
		start++;
	else if (s.at(start) == '+')
		start++;

	for (size_t i = start; i < s.size(); i++)
	{
		char tmp = s.at(i);
		if (!isdigit(tmp))
		{
			//std::cout << "going false with: " << tmp << std::endl;
			return (false);
		}
	}

	return (true);
}

	// =============== constructors =============== //

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
}

RPN RPN::operator=(const RPN &other)
{
	this->stack = other.stack;
	return *this;
}


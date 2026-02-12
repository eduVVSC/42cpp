/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 07:31:26 by edvieira          #+#    #+#             */
/*   Updated: 2026/02/12 13:21:18 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* void printStack(std::stack<int> s) {
    std::cout << "Stack (top -> bottom): ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
} */

/// @brief Check if the given string holds an math operator
/// @param s
/// @return (true - if it is) (false - if it isn't)
bool RPN::isOperand(std::string s)
{
	if (s.compare("*") == 0)
		return (true);
	if (s.compare("-") == 0)
		return (true);
	if (s.compare("+") == 0)
		return (true);
	if (s.compare("/") == 0)
		return (true);
	return (false);
}

float RPN::makeCount(std::string s)
{
	std::stack<float>	nums;

	populateStack(s);
	while (!tokens.empty())
	{
		std::string tmp = tokens.front();
		//std::cout << tmp << std::endl;

		if (isOperand(tmp))
			nums.push(execute(&nums, tmp));
		else
			nums.push(verifingAtoi(tmp));
		tokens.pop();
	}
	return (nums.top());
}

float RPN::execute(std::stack<float> *nums, std::string operation)
{

	if (nums->size() < 2)
		throw SignBadUsedException("Operator '" + operation + "', was used whithout enought numbers in stack! Review your input!");

	float n1 = nums->top();	nums->pop();
	float n2 = nums->top();	nums->pop();

	char o = operation.at(0);
	//std::cout << "Operation: " << n2 << " " << o << " " << n1 << std::endl;
	if (o == '+')
		return (n2 + n1);
	else if (o == '-')
		return (n2 - n1);
	else if (o == '/')
		return (n2 / n1);
	else if (o == '*')
		return (n2 * n1);
	return (-1); // never getting in here!
}

/// @brief Make the Atoi function and return it number
/// @param s
/// @return Conversion from string to int
/// @throw
float	RPN::verifingAtoi(std::string s)
{
	long i = atol(s.c_str());

	if (i > NUM_MAX)
		throw NumberOutOfLimitsException("Numbers given is far away from my computational capacity, values should be [0, 9] !");
	if (i < NUM_MIN)
		throw NumberOutOfLimitsException("Numbers given is far away from my computational capacity, values should be [0, 9] !");
	else
		return (static_cast<float>(i));
}

/// @brief Function will populate the queue with the tokens
/// @param s
/// @throw BadCharactersException
void RPN::populateStack(std::string s)
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
	if (isOperand(s))
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
	this->tokens = other.tokens;
	return *this;
}


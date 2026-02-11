/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 07:25:29 by edvieira          #+#    #+#             */
/*   Updated: 2026/02/11 12:18:18 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <string>
# include <stack>
# include <cstdlib>
# include <queue>

# define NUM_MAX 9
# define NUM_MIN 0

class BadCharactersException : public std::exception
{
private:
    std::string message;
public:
    BadCharactersException(const std::string& msg){this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~BadCharactersException() throw() {}
};

class SignBadUsedException : public std::exception
{
private:
    std::string message;
public:
    SignBadUsedException(const std::string& msg){this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~SignBadUsedException() throw() {}
};

class NumberOutOfLimitsException : public std::exception
{
private:
    std::string message;
public:
    NumberOutOfLimitsException(const std::string& msg){this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~NumberOutOfLimitsException() throw() {}
};

class RPN
{
private:
	std::queue<std::string> tokens;

	bool	isOperand(std::string s);
	float	verifingAtoi(std::string s);
	void	populateStack(std::string s);
	bool	onlyAllowedCharacter(std::string s);
	float  execute(std::stack<float> *nums, std::string c);

	RPN(const RPN &other);
	RPN operator=(const RPN &other);

public:
	float makeCount(std::string s);

	RPN();
	~RPN();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 07:25:29 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/19 10:18:22 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <string>
# include <stack>
# include <cstdlib>

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
	std::stack<std::string> tokens;

	bool	isOperand(std::string s);
	int		verifingAtoi(std::string s);
	void	populateStack(std::string s);
	bool	onlyAllowedCharacter(std::string s);
	int		execute(std::stack<int>	nums, std::string c);
public:

	int makeCount(std::string s);

	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN operator=(const RPN &other);
};

#endif

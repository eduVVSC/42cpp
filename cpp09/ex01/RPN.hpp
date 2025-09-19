/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 07:25:29 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/19 08:47:57 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <string>
# include <stack>
# include <queue>

class BadCharactersException : public std::exception
{
private:
    std::string message;
public:
    BadCharactersException(const std::string& msg){this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~BadCharactersException() throw() {}
};

class SignedBadUsedException : public std::exception
{
private:
    std::string message;
public:
    SignedBadUsedException(const std::string& msg){this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~SignedBadUsedException() throw() {}
};

class RPN
{
private:
	std::stack<std::string> stack;
	std::queue<std::string> tokens; // fifo

	void populateQueue(std::string s);
	bool onlyAllowedCharacter(std::string s);
public:

	int makeCount(std::string s);

	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN operator=(const RPN &other);
};

#endif

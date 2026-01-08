/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:23:52 by edvieira          #+#    #+#             */
/*   Updated: 2026/01/08 16:55:25 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>
# include <math.h>
# include <iterator>
# include <list>
# include <climits>



class FullSpanException : public std::exception{
private:
	std::string message;
public:
	FullSpanException(const std::string& msg){
		this->message = msg;
	}
	virtual const char* what() const throw(){
		return (this->message.c_str());
	}
	~FullSpanException() throw(){}
};

class IndexOutsideOfSpanException : public std::exception{
private:
	std::string message;
public:
	IndexOutsideOfSpanException(const std::string& msg){
		this->message = msg;
	}
	virtual const char* what() const throw(){
		return (this->message.c_str());
	}
	~IndexOutsideOfSpanException() throw(){}
};

class CannotCalculateException : public std::exception{
private:
	std::string message;
public:
	CannotCalculateException(const std::string& msg){
		this->message = msg;
	}
	virtual const char* what() const throw(){
		return (this->message.c_str());
	}
	~CannotCalculateException() throw(){}
};



class Span{

private:
	std::list<int> *lst;

	unsigned int	manyAdded;
	unsigned int	max;
	bool			sorted;

	void copy_values(Span const &span);

public:

	int get(unsigned int i) const;
	unsigned int getMax() const;
	unsigned int getManyAdded() const;

	void addNumber(int num);

	/// @brief Function will add all the numbers to the lst until it is not full, once it
	/// @brief got to its max, it will not add more
	/// @param vector
	template <typename T >
	void addNumber(T &cont) {
		typename T::iterator it;

		for (it = cont.begin(); it != cont.end(); it++)
			addNumber(*it);
	};

	unsigned int shortestSpan();
	unsigned int longestSpan();

	Span();
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span &operator=(Span const &other);
};

std::ostream& operator<<(std::ostream &os, const Span& span);

#endif

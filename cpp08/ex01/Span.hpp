/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:23:52 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/30 08:41:21 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>
# include <math.h>
# include <iterator>

class Span{

private:

	unsigned int	manyAdded;
	unsigned int	max;
	int				*arr;

public:

	int get(unsigned int i) const;
	unsigned int getMax() const;
	unsigned int getManyAdded() const;

	void addNumber(int num);

	//void addNumber(std::vector<int> vector);

	template <typename T >
	void addNumber(T &cont) {
		typename T::iterator beg = cont.begin();
		typename T::iterator last = cont.end();

		while (beg != last)
		{
			if (manyAdded == max)
				break;
			arr[manyAdded] = *beg;

			manyAdded++;
			beg++;
		}
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



#endif

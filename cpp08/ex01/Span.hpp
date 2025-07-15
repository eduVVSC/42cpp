/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:23:52 by edvieira          #+#    #+#             */
/*   Updated: 2025/07/15 13:25:40 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <math.h>

class Span{
private:
	unsigned int manyAdded;
	unsigned int max;
	int *arr;

public:
	int get(unsigned int i) const;
	unsigned int getMax() const;
	unsigned int getManyAdded() const;

	void addNumber(int num);
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

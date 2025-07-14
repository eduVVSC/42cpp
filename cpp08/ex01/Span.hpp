/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:23:52 by edvieira          #+#    #+#             */
/*   Updated: 2025/07/14 07:29:30 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span{
private:
	int manyAdded;
	int max;
	int *arr;
public:
	void addNumber();
	int shortestSpan();
 	int longestSpan();

	Span();
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span &operator=(Span const &other);
};

#endif

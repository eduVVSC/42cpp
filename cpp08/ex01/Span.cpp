/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:23:42 by edvieira          #+#    #+#             */
/*   Updated: 2025/07/14 07:29:08 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::addNumber(){

}

int Span::shortestSpan(){

}

int Span::longestSpan(){

}


Span::Span(){
	manyAdded = 0;
	max = 1;
	arr = new int[1];
}

Span::Span(unsigned int N){
	manyAdded = 0;
	max = N;
	arr = new int[N];
}

Span::Span(const Span &other){
	*this = other;
}

Span::~Span(){
}


Span& Span::operator=(Span const &other)
{
	if (this->arr != NULL)
		delete this->arr
}

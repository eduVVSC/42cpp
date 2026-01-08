/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:23:42 by edvieira          #+#    #+#             */
/*   Updated: 2026/01/08 16:51:22 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/// @brief Function will add a number to the arr if it is not full
/// @brief and will sort it inside
/// @param num
void Span::addNumber(int num)
{
	if (manyAdded < max)
	{
		lst->push_back(num);
		sorted = false;
		manyAdded++;
	}
	else
		throw FullSpanException("Span is already full!");
}

/// @brief Function searches for the shortestSpan in the array saved if possible
/// @brief  If it isn't possible it will throw and exception
/// @return (shortestSpan)
unsigned int Span::shortestSpan(){
	std::list<int>::iterator it;
	unsigned int shortestSpan = UINT_MAX;
	int num1;
	int num2;

	if (!sorted)
		lst->sort();
	sorted = true;

	if (max <= 1 || manyAdded <= 1)
		throw CannotCalculateException("Not enough items to calculate span!");
	it = lst->begin();

	for (unsigned int i = 0; i < (manyAdded - 1); i++)
	{
		num1 = *it;
		it++;
		num2 = *it;

		unsigned int diff = num2 - num1;
		if (diff < shortestSpan)
			shortestSpan = diff;
	}
	return (shortestSpan);
}

/// @brief Function searches for the longestSpan in the array saved if possible
/// @brief  If it isn't possible it will throw and exception
/// @return (longestSpan)
unsigned int Span::longestSpan(){
	int	minVal;
	int	maxVal;

	if (!sorted)
		lst->sort();

	sorted = true;
	if (max <= 1 || manyAdded <= 1)
		throw CannotCalculateException("Not enough items to calculate span!");

	minVal = lst->front();
	maxVal = lst->back();
	return (static_cast<unsigned int> (std::abs(maxVal - minVal)));
}

unsigned int Span::getMax() const { return (max);}

unsigned int Span::getManyAdded() const { return (manyAdded);}

int Span::get(unsigned int i) const {
	if (i < manyAdded)
	{
		std::list<int>::iterator it = lst->begin();
		for (unsigned int j = 0; j < i; j++)
			++it;
		return *it;
	}
	else if (i < max)
		return (0); // all values are started to 0
	else
		throw IndexOutsideOfSpanException("Index outside of span size");
}

void Span::copy_values(Span const &span)
{
	int to_copy = span.getManyAdded();

	for (int i = 0; i < to_copy; i++)
		addNumber(span.get(i));
}

Span::Span(){
	max = 1;
	manyAdded = 0;
	sorted = false;
	lst = new std::list<int> ();
}

Span::Span(unsigned int N){
	max = N;
	manyAdded = 0;
	sorted = false;
	lst = new std::list<int> ();
}

Span::Span(const Span &other){
	this->lst = NULL;
	sorted = false;
	*this = other;
}

Span::~Span(){
	delete lst;
}

Span& Span::operator=(Span const &other)
{
    sorted = false;
    if (this != &other)
    {
        if (this->lst != NULL)
            delete lst;

        this->max = other.max;
        this->manyAdded = 0;
        lst = new std::list<int> ();
        copy_values(other);
    }
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Span& s) {
	for (size_t i = 0; i < s.getManyAdded(); i++)
	{
		os << s.get(i) << " ";
	}
	return (os);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:23:42 by edvieira          #+#    #+#             */
/*   Updated: 2025/07/15 14:50:07 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/// @brief Function will add a number to the arr if it is not full
/// @param num
void Span::addNumber(int num) {
	if (manyAdded < max) {
		arr[manyAdded] = num;
		manyAdded++;
	}
	else
		throw FullSpanException("Span is already full!");
}

/// @brief Function will add all the numbers to the arr until it is not full, once it got to its max, it will not add more
/// @param vector
void Span::addNumber(std::vector<int> vector) {
	size_t i = 0;
	while (manyAdded < max && i < vector.size())
	{
		arr[manyAdded] = vector.at(i);
		manyAdded++;
		i++;
	}
}

/// @brief Function searches for the shortestSpan in the array saved if possible
/// @brief  If it isn't possible it will throw and exception
/// @return (shortestSpan)
unsigned int Span::shortestSpan(){
	unsigned int shortestSpan = 1410065408; // later change it to max unsigned int

	if (max == 1 || manyAdded == 1)
		throw CannotCalculateException("Not enought items to calculate span!");
	for (size_t i = 0; i < manyAdded; i++)
	{
		for (size_t j = (i + 1); j < manyAdded; j++)
		{
			if (std::abs(arr[i] - arr[j]) < shortestSpan)
				shortestSpan = std::abs(arr[i] - arr[j]);
		}
	}
	return (shortestSpan);
}


/// @brief Function searches for the longestSpan in the array saved if possible
/// @brief  If it isn't possible it will throw and exception
/// @return (longestSpan)
unsigned int Span::longestSpan(){
	unsigned int longestSpan = 0;

	if (max == 1 || manyAdded == 1)
		throw CannotCalculateException("Not enought items to calculate span!");
	for (size_t i = 0; i < manyAdded; i++)
	{
		for (size_t j = (i + 1); j < manyAdded; j++)
		{
			if (std::abs(arr[i] - arr[j]) > longestSpan)
				longestSpan = std::abs(arr[i] - arr[j]);
		}
	}
	return (longestSpan);
}

unsigned int Span::getMax() const { return (max);}

unsigned int Span::getManyAdded() const { return (manyAdded);}

int Span::get(unsigned int i) const {
	if (i >= max)
		throw IndexOutsideOfSpanException("Index outside of span size");
	return (arr[i]);
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
	this->arr = NULL;
	*this = other;
}

Span::~Span(){
	delete [] arr;
}

Span& Span::operator=(Span const &other)
{
	//std::cout << "inside equal operator" << std::endl;
	if (this->arr && this->arr != NULL)
	{
		//std::cout << "inside if " << std::endl;
		delete [] this->arr;
	}

	//std::cout << "array deleted" << std::endl;
	this->arr = new int[other.max];
	//std::cout << "array created" << std::endl;
	this->manyAdded = other.manyAdded;
	this->max = other.max;

	for (size_t i = 0; i < manyAdded; i++)
		this->arr[i] = other.arr[i];
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Span& span) {
	for (size_t i = 0; i < span.getManyAdded(); i++)
	{
		os << span.get(i) << " ";
	}
	return (os);
}

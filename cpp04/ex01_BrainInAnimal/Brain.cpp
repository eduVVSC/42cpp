/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:17:19 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:51:55 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

void Brain::copyIdeas(std::string *oIdeas) {
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = oIdeas[i];
	}
}

void Brain::addIdea(std::string idea){
	bool added = false;

	if (idea.empty() || !idea.compare("\n"))
	{
		std::cout << "No ideas were inputed!" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 100; i++) {
		if (this->ideas[i].empty())
		{
			ideas[i] = idea;
			added = true;
			break ;
		}
	}
	if (added == false)
		std::cout << "Brain is already full!! Cannot keep more information!!" << std::endl;
}

std::string *Brain::getIdeas(){ return (this->ideas);}

Brain::Brain()
{
	std::cout << "🧠 Brain Created!"<< std::endl;
}

Brain &Brain::operator=(const Brain &other){
	(void) other;
	//copyIdeas(other.getIdeas());
	return (*this);
}

Brain::Brain(Brain &other)
{
	std::cout << "Brain Created!"<< std::endl;
	copyIdeas(other.getIdeas());
}

Brain::~Brain(){
	std::cout << "🧠 Brain Destroyed!"<< std::endl;
}

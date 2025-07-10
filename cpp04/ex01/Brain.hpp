/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:02:42 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 15:34:34 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
		void copyIdeas(const Brain &other);

	public:
		void addIdea(std::string idea);
		std::string *getIdeas();
		void displayIdeas();
		
		Brain(const Brain &copy);
		Brain();
		
		~Brain();
		Brain&operator=(const Brain &other);
};

#endif

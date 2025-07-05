/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:11:34 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/09 13:49:52 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

struct ComplainType {
	enum Type {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		NONE
	};
};

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		int getHash(std::string level);
		
	public:

		void complain( std::string level );

		Harl();

		~Harl();
};


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:13:31 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/24 21:53:30 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{	
	if (ac == 1) {
		Harl h;
		std::cout << "============ DEBUG ============" << std::endl;
		h.complain("DEBUG");
		std::cout << "============ INFO ============" << std::endl;
		h.complain("INFO");
		std::cout << "============ WARNING ============" << std::endl;
		h.complain("WARNING");
		std::cout << "============ ERROR ============" << std::endl;
		h.complain("ERROR");
		std::cout << "============ NOT AVAILABLE MESSAGE ============" << std::endl;
		h.complain("NOT AVAILABLE MESSAGE");
	}
	if (ac == 2)
	{
		Harl h;
		h.complain(av[1]);
	}
	return (0);
}

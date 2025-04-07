/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:01:26 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 17:48:50 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN"	;
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::string str2 = str;

	std::cout << "--Address value--" << std::endl;
	std::cout << "str    |" << &str << "|"<< std::endl;
	std::cout << "str2   |" << &str2 << "|"<< std::endl;
	std::cout << "strPTR |" << stringPTR << "|"<< std::endl;
	std::cout << "strREF |" << &stringREF << "|"<< std::endl;

	std::cout << "\n--Value of variable--" << std::endl;
	std::cout << "str    |" << str << "|"<< std::endl;
	std::cout << "str2   |" << str2 << "|"<< std::endl;
	std::cout << "strPTR |" << stringPTR << "|"<< std::endl;
	std::cout << "strREF |" << stringREF << "|"<< std::endl;

	return (0);
}

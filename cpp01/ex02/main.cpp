/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:01:26 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/02 22:11:49 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
/* do later!!! */

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	//std::string stringREF = (char *)*str;

	std::cout << "str    |" << str << "|"<< std::endl;
	std::cout << "strPTR |" << stringPTR << "|"<< std::endl;
	//std::cout << "strREF |" << str << "|"<< std::endl;

	return (0);
}

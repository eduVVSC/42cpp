/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:00 by edvieira          #+#    #+#             */
/*   Updated: 2026/02/09 17:24:02 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> atoiAllEntries(int ac, char **av)
{
	std::vector<int> vec;

	for (int i = 1; i < ac; i++)
	{
		char *endptr;
		errno = 0;
		long num = strtol(av[i], &endptr, 10);

		// Check for overflow/underflow or out of int range
		if (errno == ERANGE || num > INT_MAX || num < 0)
			return (vec.clear(), vec);

		// Check if the entire string was converted (no invalid characters)
		if (*endptr != '\0' || endptr == av[i])
			return (vec.clear(), vec);

		int temp = static_cast<int>(num);

		// Check for duplicates
		if (std::find(vec.begin(), vec.end(), temp) != vec.end())
			return (vec.clear(), vec);

		vec.push_back(temp);
	}
	return (vec);
}

int main(int ac, char **av)
{
	std::vector<int> enteredValues;

	if (ac > 1)
	{
		enteredValues = atoiAllEntries(ac, av);
		if (enteredValues.empty())
			return (std::cerr << "You need to enter unique positive integers to the program work!" << std::endl, 1);
		PmergeMe p(&enteredValues);
	}
	return 0;
}

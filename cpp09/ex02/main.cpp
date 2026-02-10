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

int	ft_atoi_w_valid(char *str)
{
	int	num = 0;
	int	i = 0;

	if (str[i] == 0) // * validation of empty str
		return (-1);
	while (str[i] != '\0')
	{
		if(str[i] > '9' || str[i] < '0')
			return (-1);

		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

std::list<int>	atoiAllEntries(int ac, char **av)
{
	std::list<int> list;
	int	temp;

	for (int i = 1; i < ac; i++)
	{
		temp = ft_atoi_w_valid(av[i]);
		if (temp == -1)
		{
			list.clear();
			return (list);
		}
		list.push_back(temp);
	}
	return (list);
}

int main(int ac, char **av)
{
	std::list<int> enteredValues;

	if (ac > 1)
	{
		enteredValues = atoiAllEntries(ac, av);
		if (enteredValues.empty())
			return (std::cerr << "You need to enter positive integer(without sign) to the program work!" << std::endl, 1);
		PmergeMe p(&enteredValues);
	}
	return 0;
}

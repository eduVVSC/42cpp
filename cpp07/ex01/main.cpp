/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:53:46 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/29 20:33:38 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void ft_print(int &val)
{
	std::cout << "\t" << val << std::endl;
}

void ft_print_c(const int &val)
{
	std::cout << "\t" << val << std::endl;
}

int main()
{

	char a[] = {'A', 'B', 'C'};

	std::cout << "Original:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	::iter<char >(a, 3, ft_tolower);

	std::cout << "Changed:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	std::cout << "Test print:" << std::endl;

	int b[] = { 0, 1, 2, 3, 4};
	::iter<int >( b ,4, ft_print);

	std::cout << "Const test:" << std::endl;

	const int c[] = {1, 2, 3};

	::iter(c, 3, ft_print_c);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:00 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/30 08:42:03 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

void subjectMain()
{
	std::cout << "\n=============== Subject Main ===============" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}


int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(-3);
		sp.addNumber(6);
		sp.addNumber(9);
		sp.addNumber(11);
		

		Span test = sp;

		sp.addNumber(17);
		std::cout << "=============== 1st created Span ===============" << std::endl;
		std::cout << test << std::endl;

		std::cout << "=============== Copy created Span ===============" << std::endl;
		std::cout << sp << std::endl;

		std::cout << std::endl;
		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << sp.longestSpan() << std::endl;

		std::cout << "\n=============== exception test ===============" << std::endl;
		Span sp2 = Span();
		sp2.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: Could not complete task: " << e.what() << '\n';
	}


	try
	{
		std::cout << "\n=============== Fast adition with vector test ===============" << std::endl;
		std::vector<int> numbers;
		numbers.push_back(1); 
		numbers.push_back(2); 
		numbers.push_back(3); 

		Span testNums = Span(5);
		testNums.addNumber(numbers);
		// testNums.addNumber(numbers); // this will fail because it will go over span size!
		std::cout << testNums << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: Could not complete task: " << e.what() << '\n';
	}
	

	subjectMain();
	return 0;
}

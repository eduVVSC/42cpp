/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:00 by edvieira          #+#    #+#             */
/*   Updated: 2026/01/08 16:59:06 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void testBasicSpanOperations() {
	std::cout << "=== Test 1: Basic Span Operations ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(-3);
		sp.addNumber(6);
		sp.addNumber(9);
		sp.addNumber(11);
		

		std::cout << "=============== 1st created Span ===============" << std::endl;
		std::cout << sp << std::endl;

		Span test;
		test = sp;
		std::cout << "=============== Copy created Span ===============" << std::endl;
		std::cout << test << std::endl;
		std::cout << std::endl;

		sp.addNumber(17);
		std::cout << "Addition of number 17 to copy" << std::endl;
		std::cout << "=============== 1st created Span ===============" << std::endl;
		std::cout << test << std::endl;
		std::cout << "=============== Copy created Span ===============" << std::endl;
		std::cout << sp << std::endl;
		std::cout << std::endl;

		std::cout << "✓ Test passed" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "✗ Exception: " << e.what() << '\n';
	}
	std::cout << std::endl;
}

void testFastAdditionWithVector() {
	std::cout << "=== Test 2: Fast Addition with Vector ===" << std::endl;
	try {
		std::vector<int> numbers;
		numbers.push_back(1);
		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(2);
		numbers.push_back(3);
		numbers.push_back(3);

		Span testNums = Span(6);
		testNums.addNumber(numbers);

		std::cout << testNums << std::endl;
		std::cout << "✓ Test passed" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "✗ Exception: " << e.what() << '\n';
	}
	std::cout << std::endl;
}

void testExceptionHandling() {
	std::cout << "=== Test 3: Exception Handling ===" << std::endl;
	try {
		std::cout << "=============== No numbers ===============" << std::endl;

		Span sp2 = Span();
		sp2.shortestSpan();
		std::cerr << "✗ Should have thrown exception!" << std::endl;
	} catch(const std::exception& e) {
		std::cout << "✓ Exception caught as expected: " << e.what() << '\n';
	}
	std::cout << std::endl;

	try {
		std::cout << "=============== 1 number ===============" << std::endl;
		Span sp2 = Span();
		sp2.addNumber(1);

		sp2.shortestSpan();
		std::cerr << "✗ Should have thrown exception!" << std::endl;
	} catch(const std::exception& e) {
		std::cout << "✓ Exception caught as expected: " << e.what() << '\n';
	}
	std::cout << std::endl;
}

void testSpan() {
	std::cout << "=== Test 1: Positive Values ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(3);
		sp.addNumber(6);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Span: " << sp << std::endl;
		std::cout << std::endl;

		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
		std::cout << "✓ Test passed" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "✗ Exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Negative Values ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(-3);
		sp.addNumber(-6);
		sp.addNumber(-9);
		sp.addNumber(-11);

		std::cout << "Span: " << sp << std::endl;
		std::cout << std::endl;

		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
		std::cout << "✓ Test passed" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "✗ Exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Mixed Values ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(3);
		sp.addNumber(-6);
		sp.addNumber(9);
		sp.addNumber(-11);

		std::cout << "Span: " << sp << std::endl;
		std::cout << std::endl;

		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
		std::cout << "✓ Test passed" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "✗ Exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "=== Test: Large Span with 10000 Numbers (using vector) ===" << std::endl;
	try {
		Span sp = Span(10000);
		std::vector<int> numbers;

		for (int i = 0; i < 10000; i++)
		{
			if (i % 3 == 0)
				numbers.push_back(i);
			else if (i % 3 == 1)
				numbers.push_back(-i);
			else
				numbers.push_back(i / 2);
		}

		sp.addNumber(numbers);

		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
		std::cout << "✓ Test passed" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "✗ Exception: " << e.what() << '\n';
	}
	std::cout << std::endl;
}

int main() {
	testBasicSpanOperations();
	testFastAdditionWithVector();
	testExceptionHandling();
	testSpan();

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:05:51 by edvieira          #+#    #+#             */
/*   Updated: 2026/01/08 11:38:27 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iterator>

void testEasyfind() {
	std::cout << "=== Testing easyfind function ===" << std::endl;

	// Test 1: Found in vector
	std::cout << "\nTest 1: Search for existing element in vector" << std::endl;
	try {
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);

		std::vector<int>::iterator vit = easyfind(vec, 20);
		(void) vit;
		std::cout << "✓ Found in vector: " << *vit << std::endl;
	} catch (const NotFoundException &e) {
		std::cerr << "✗ Unexpected exception: " << e.what() << std::endl;
	}

	// Test 2: Not found in vector
	std::cout << "\nTest 2: Search for non-existing element in vector" << std::endl;
	try {
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);

		std::vector<int>::iterator vit = easyfind(vec, 42);
		(void) vit;
		std::cerr << "✗ Should have thrown exception!" << std::endl;
	} catch (const NotFoundException &e) {
		std::cout << "✓ Exception caught as expected: " << e.what() << std::endl;
	}

	// Test 3: Test with std::list
	std::cout << "\nTest 3: Search in std::list" << std::endl;
	try {
		std::list<int> lst;
		lst.push_back(100);
		lst.push_back(200);
		lst.push_back(300);

		std::list<int>::iterator lit = easyfind(lst, 200);
		std::cout << "✓ Found in list: " << *lit << std::endl;
	} catch (const NotFoundException &e) {
		std::cerr << "✗ Unexpected exception: " << e.what() << std::endl;
	}

	// Test 4: Empty container
	std::cout << "\nTest 4: Search in empty container" << std::endl;
	try {
		std::vector<int> vec;
		std::vector<int>::iterator vit = easyfind(vec, 1);
		(void) vit;
		std::cerr << "✗ Should have thrown exception!" << std::endl;
	} catch (const NotFoundException &e) {
		std::cout << "✓ Exception caught for empty container: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
}

int main() {
	testEasyfind();
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:05:51 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/30 07:45:08 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iterator>


int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::vector<int>::iterator vit = easyfind(vec, 20);
        std::cout << "Found in vector: " << *vit << std::endl;

		vit = easyfind(vec, 42);

    } catch (const NotFoundException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

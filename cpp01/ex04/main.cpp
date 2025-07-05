/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:32:09 by edvieira          #+#    #+#             */
/*   Updated: 2025/05/05 16:07:07 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

 void writeLineChange(std::ofstream *writeFile, std:: string line, std::string s1, std::string s2)
{
	size_t positionFound = line.find(s1);
	// std::string::npos, standard constant to did not find
	if (positionFound == std::string::npos)
	{
		writeFile->write(line.c_str(), line.length());
	}
	else
	{
		writeFile->write(line.c_str(), positionFound);
		writeFile->write(s2.c_str(), s2.length());
		if ((positionFound + s1.length()) < line.length()) {
			std::string restOfLine = line.substr(positionFound + s1.length(), s1.length());
			writeFile->write(restOfLine.c_str(), restOfLine.length());
		}
	}
}

void replace(std::string filename, std::string s1, std::string s2)
{
 	std::ifstream readFile(filename.c_str());
 	if (readFile.is_open())
 	{
 		std::string line;
 		std::ofstream writeFile(filename.append(".replace").c_str()); // need to check if the file exists before!!
		if (writeFile.fail()) {
			std::cout << "Could not open file " << filename << ". Exiting." << std::endl;
			return ;
		}
 		while (getline(readFile, line))
 		{
 			writeLineChange(&writeFile, line, s1, s2);
 			writeFile.put('\n');
 		}
 		readFile.close();
 	}
 	else
 		std::cout << "You've inserted a bad filename!!!" << std::endl;
}

int	main(int ac, char **av)
{
	if (ac == 4)
		replace(av[1], av[2], av[3]);
	else {
		std::cerr << "Bad Arguments! Correct usage:\n " << av[0] << " <filename> <to be replaced> <to replace with>" << std::endl;
	}
	return (0);
}

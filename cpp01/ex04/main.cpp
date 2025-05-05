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


// s1 to be replaced by s2
void writeLineChange(std::ofstream *writeFile, std:: string line, char *s1, char *s2)
{
	(void) s2;
	(void) writeFile;
	for (size_t i = 0; i < line.length(); i++)
	{
		if (i == line.find(s1, i))
		{
			size_t wordLen = strlen(s2);
			for (size_t i = 0; i < wordLen; i++)
				writeFile->put(s2[i]);
			i += strlen(s1) - 1;
		}
		else
			writeFile->put(line.at(i));
	}
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename;
		filename = av[1];

		std::ifstream readFile(filename.c_str());
		if (readFile.is_open())
		{
			std::string line;
			std::ofstream writeFile(filename.append(".replace").c_str()); // need to check if the file exists before!!

			std::cout << "file is opened" << std::endl;

			while (getline(readFile, line))
			{
				std::cout << line << std::endl;
				writeLineChange(&writeFile, line, av[2], av[3]);
				writeFile.put('\n');
			}

			readFile.close();
		}
		else
			std::cout << "You've inserted a bad file!!!" << std::endl;
	}
	return (0);
}

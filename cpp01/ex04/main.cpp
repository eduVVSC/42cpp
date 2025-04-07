/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:32:09 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/07 18:18:55 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

void writeLineChange(std::ofstream *writeFile, std:: string line, char *s1, char *s2)
{
	const char *lineInChar = line.c_str();
	size_t	whereToStop;
	size_t	i = -1;

	whereToStop = line.find(s1);
	while (++i < whereToStop)
		writeFile->put(lineInChar[i]);


	for (size_t j = 0; j < strlen(s2); j++)
		writeFile->put(s2[j]);

	i = i + strlen(s1);
	while (++i < line.length())
		writeFile->put(lineInChar[i]);
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
				std::cout << line;
				/* if (!line.find(av[2]))// error is in here!
					//writeLineChange(&writeFile, line, av[2], av[3]);
				writeFile.write(line.c_str(), line.length()); */
				writeFile.put('\n');
				std::cout << std::endl;
			}

			readFile.close();
		}
		else
			std::cout << "You've inserted a bad file!!!" << std::endl;
	}
	return (0);
}

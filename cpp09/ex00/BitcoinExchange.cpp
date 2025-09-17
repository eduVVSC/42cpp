/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:49:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/17 11:49:34 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ------------------------- Date functions -------------------------  */

int Date::getYear() { return (year); }
int Date::getMonth() { return (month); }
int Date::getDay() { return (day); }
double Date::getValue() { return (value); }

/// @brief Compare the distance in time between two dates
/// @param other
/// @return The distance between them in a positive integer
int Date::compare(Date &other)
{
	int distance;

	distance = 365 * (std::max(this->year, other.getYear()) - std::min(this->year, other.getYear()));
	distance += 30 * (std::max(this->month, other.getMonth()) - std::min(this->month, other.getMonth()));
	distance += 1 * (std::max(this->day, other.getDay()) - std::min(this->day, other.getDay()));
	return (distance);
}

/// @brief Function will read the date section of the line and parse it
/// @param line
/// @return (true - well difined) (false - bad difined)
bool Date::readDate(std::string line)
{
	int occurrences = 0;
	for (size_t i = 0; i < line.size(); i++)
	{
		char c = line.at(i);
		if (c == '-')
		{
			occurrences++;
			continue;
		}
		if (isdigit(c))
			continue;
		return (false);
	}

	if (occurrences != 2)
		return (false);

	char	*end;
	int		first = line.find('-');
	int		last  = line.find_last_of('-');

	this->year  = static_cast<int>(strtol(line.substr(0, (first - 1)).c_str(), &end, 10));
	this->month = static_cast<int>(strtol(line.substr((first + 1), (last - 1)).c_str(), &end, 10));
	this->day   = static_cast<int>(strtol(line.substr((last + 1), line.size()).c_str(), &end, 10));

	return (true);
}

Date::Date()
{
}

Date::Date(std::string line)
{
	if (line.find(',') == std::string::npos)
		throw new BadDateException("Line was not defined correctly, without ','.\n");
	else
	{
		char* end;

		errno = 0;

		// get date
		std::string date = line.substr(0, (line.find(',') - 1));
		if (!readDate(date))
			throw new BadDateException("Date was not correctly defined!\n");
		// get value
		this->value = static_cast<double>(strtol(line.substr(line.find(','), line.size()).c_str(), &end, 10));
		if (errno == ERANGE)
			throw new BadDateException("Line was not defined correctly, without ','.\n");
	}
}

Date::Date(const Date &other)
{
	this->day   = other.day;
	this->month = other.month;
	this->year  = other.year;
	this->value = other.value;
}

Date::~Date() {}

/* ------------------------- ------------------------- -------------------------  */

/* ------------------------- Bitcoin Excahnge functions -------------------------  */

std::string BitcoinExchange::readAll(std::ifstream& inFile)
{
	(void) inFile;
	return NULL;
}

void BitcoinExchange::readDatabaseValues(std::ifstream& inFile)
{
	std::string line;
	try
	{
		while (std::getline (inFile, line))
		{
			if (line.empty())
				throw new BadDateException("No date nor info in one line, fix your database!\n");
			//db.push_back(Date(line));
			std::cout << line << std::endl;
		}
	}
	catch (const std::exception& e) {
		throw e;
		}
}

Date BitcoinExchange::getDateRate(Date searchDate)
{
	(void) searchDate;
	return Date();
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream inFile(DATABASE_FILE);

	if (inFile.is_open())
	{
		try {
			readDatabaseValues(inFile);
		}
		catch(const std::exception& e)
		{
			// clean the database and finish program!
			std::cerr << e.what() << '\n';
			throw e;
		}
	}
	else
		throw new CouldNotOpenFileException("Database file could not be opened!\n");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void) other;
}

BitcoinExchange::~BitcoinExchange()
{
	db.clear();
}

/* ------------------------- ------------------------- -------------------------  */

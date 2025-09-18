/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:49:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/18 08:40:11 by edvieira         ###   ########.fr       */
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

/// @brief Function validate if the date is corret according to the normal standards
/// @return (true - valid date) (false - invalid date)
bool Date::validDate(){
	if (this->day > DAY_MAX)
		return false;
	if (this->month > MONTH_MAX)
		return false;
	if (this->year > YEAR_MAX)
		return false;

	// VALIDATE BETTER LATER!

	return (true);
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

	this->year  = static_cast<int>(strtol(line.substr(0, (first)).c_str(), &end, 10));
	this->month = static_cast<int>(strtol(line.substr((first + 1), (last - 1)).c_str(), &end, 10));
	this->day   = static_cast<int>(strtol(line.substr((last + 1), line.size()).c_str(), &end, 10));

	return (validDate());
}

Date::Date()
{
}

Date::Date(std::string line)
{
	if (line.find(',') == std::string::npos)
		throw BadDateException("Line was not defined correctly, without ','.");
	else
	{
		char* end;


		// -- get date
		std::string date = line.substr(0, (line.find(',')));
		if (!readDate(date))
			throw BadDateException("Date was not correctly defined!\n");

		// -- get value
		this->value = static_cast<double>(strtod(line.substr((line.find(',') + 1), line.size()).c_str(), &end));
		if (value < 0)
			throw BadValueException("Value is lower than 0, not allowed!");
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

void Date::print() { std::cout << year << "-" << month << "-" << day << "," << value << std::endl; }


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
		std::getline (inFile, line);
		while (std::getline (inFile, line))
		{
			if (line.empty())
				throw BadDateException("No date nor info in one line, fix your database!\n");
			Date tmp = Date(line);
			db.push_back(tmp); // breaking here
			//std::cout << line << "\t";
			tmp.print();
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << " -> in exception in readDatabaseValues\n" << std::endl;
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
		catch(std::exception& e)
		{
			// clean the database and finish program!

			// no need to print in here, it's being printer the error in the readDatabseValues

			throw e;
		}
	}
	else
		throw CouldNotOpenFileException("Database file could not be opened!\n");
	/* std::list<Date>::iterator it;
	for (it = db.begin(); it != db.end(); ++it) {
		it->print();
	} */
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

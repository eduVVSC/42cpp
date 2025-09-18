/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:49:49 by edvieira          #+#    #+#             */
/*   Updated: 2025/09/18 10:44:22 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string concatChar(const std::string& s, char c) {
    return s + c;
}

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
	int distance = 0;

	//std::cout << "---------------------" << std::endl;
	//this->print();
	//other.print();

	distance = 365 * (std::max(this->year, other.getYear()) - std::min(this->year, other.getYear()));
	distance += 30 * (std::max(this->month, other.getMonth()) - std::min(this->month, other.getMonth()));
	distance += 1 * (std::max(this->day, other.getDay()) - std::min(this->day, other.getDay()));


	//std::cout << "distance : " << distance << std::endl;
	//std::cout << std::endl;
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
		if (isdigit(c) || c == ' ')
			continue;
		return (false);
	}

	if (occurrences != 2)
		return (false);

	//std::cout << "-started reading-" << std::endl;
	char	*end;
	int		first = line.find('-');
	int		last  = line.find_last_of('-');

	this->year  = static_cast<int>(strtol(line.substr(0, (first)).c_str(), &end, 10));
	this->month = static_cast<int>(strtol(line.substr((first + 1), (last - 1)).c_str(), &end, 10));
	this->day   = static_cast<int>(strtol(line.substr((last + 1), line.size()).c_str(), &end, 10));

	return (validDate());
}

void Date::print() { std::cout << year << "-" << month << "-" << day << "," << value << std::endl; }

Date::Date()
{
}

Date::Date(std::string line, char separator)
{
	if (line.find(separator) == std::string::npos)
		throw BadDateException(concatChar("Line was not defined correctly, without ", separator));
	else
	{
		// -- get date
		std::string date = line.substr(0, (line.find(separator)));
		if (!readDate(date))
			throw BadDateException("bad input => " + date);

		// -- get value
		char* end;
		this->value = static_cast<double>(strtod(line.substr((line.find(separator) + 1), line.size()).c_str(), &end));
		if (value < VALUE_MIN)
			throw BadValueException("not a positive number.");
		if (separator == '-' && value > VALUE_MAX)
			throw BadValueException("too large a number.");
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

Date Date::operator=(const Date &other)
{
	this->day = other.day;
	this->year = other.year;
	this->month = other.month;
	this->value = other.value;

	return (*this);
}


/* ------------------------- ------------------------- -------------------------  */

/* ------------------------- Bitcoin Excahnge functions -------------------------  */

/// @brief Read the new data(.csv) and to the convertion of the sold bitcoin with it's values
/// @param inFile
void BitcoinExchange::convert(std::string filename)
{
	std::ifstream inFile(filename.c_str());
	std::string line;

	if (inFile.is_open())
	{
		std::getline (inFile, line); // jumping first line!

		while (std::getline (inFile, line))
		{
			if (line.empty())
				std::cout << "Error: empty line." << std::endl;
			else
			{
				try {
					Date tmp = Date(line, '|');
					std::cout << tmp.getYear() << "-" << tmp.getMonth() << "-" << tmp.getDay() << " => "
					<< tmp.getValue() << " = " << getFullRate(tmp) << std::endl;
				}
				catch(const std::exception& e) {
					std::cerr << "Error: " << e.what() << '\n';
				}
			}
		}
	}
	else
		throw CouldNotOpenFileException("Database file could not be opened!\n");
}

/// @brief Function will populate the database of the program with the value in each date of bitcoin
/// @param inFile
/// @throw CouldNotOpenFileException - BadDateException - BadValueException
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
			Date tmp = Date(line, ',');
			db.push_back(tmp);
			//tmp.print();
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << " -> in exception in readDatabaseValues\n" << std::endl;
		throw e;
	}
}

/// @brief Search for the closest rate of the bitcoin to a wanted date
/// @param searchDate
/// @return (bitcoin value in the closest date)
double BitcoinExchange::getFullRate(Date searchDate)
{
	std::list<Date>::iterator it;
	Date tmpDate = db.front();
	double tmpDist = searchDate.compare(tmpDate);
	double tmpValue = searchDate.getValue();

	for (it = db.begin(); it != db.end(); ++it)
	{
		//std::cout << "value is " << it->getValue() << std::endl;
		if (searchDate.compare(*it) < tmpDist)
		{
			tmpDist = searchDate.compare(*it);
			tmpValue = it->getValue();
		}
		tmpDate = *it;
	}
	//std::cout << " value found: " << tmpValue << std::endl;
	//std::cout << "\nclosest value is" << tmpValue << " " <<  tmpDist << std::endl;
	return (tmpValue * searchDate.getValue());
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream inFile(DATABASE_FILE);

	if (inFile.is_open())
	{
		try {
			readDatabaseValues(inFile);
		}
		catch(std::exception& e) {
			throw e;
		}
	}
	else
		throw CouldNotOpenFileException("Database file could not be opened!\n");
	std::list<Date>::iterator it;
	/* for (it = db.begin(); it != db.end(); ++it) {
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

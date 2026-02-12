/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:49:49 by edvieira          #+#    #+#             */
/*   Updated: 2026/02/12 10:43:20 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/* ------------------------- Date functions -------------------------  */


/// @brief Compare the distance in time between two dates
/// @param other
/// @return The distance between them
int Date::compare(Date &other)
{
	int distance = 0;


	distance = 365 * (this->year - other.getYear());
	distance += 30 * (this->month - other.getMonth());
	distance += 1 * (this->day - other.getDay());

	return (distance);
}

/// @brief Function validate if the date is corret according to the normal standards
/// @return (true - valid date) (false - invalid date)
bool Date::validDate(){
	if (this->year < YEAR_MIN)
		return (false);
	if (this->year == YEAR_MIN && this->month < MONTH_MIN)
		return false;
	if (this->year == YEAR_MIN && this->month == MONTH_MIN && this->day < DAY_MIN)
		return false;

	struct tm t_s = {};
	t_s.tm_year = year - 1900;
	t_s.tm_mon = month - 1;
	t_s.tm_mday = day;

	// Validate actual date
	struct tm cache_t = t_s;
	if (mktime(&cache_t) == -1)
		return (false);

	if (t_s.tm_year != cache_t.tm_year
		|| t_s.tm_mon != cache_t.tm_mon
		|| t_s.tm_mday != cache_t.tm_mday)
		return (false);

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
		std::string val = trim(line.substr((line.find(separator) + 1), line.size()));	
		
		if (!hasOnlyNumbersAndDots(val))
			throw BadValueException("Databse line with random characters in it! Not allowed.");

		this->value = static_cast<double>(strtod(line.substr((line.find(separator) + 1), line.size()).c_str(), &end));

		if (value < VALUE_MIN)
			throw BadValueException("not a positive number.");
		if (separator == '|' && value > VALUE_MAX)
			throw BadValueException("too large a number.");
	}
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
	
bool Date::operator==(const Date& other) const 
{
	return day == other.day && 
			month == other.month && 
			year == other.year;
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

			if (std::find(db.begin(), db.end(), tmp) != db.end())
				throw BadDateException("One date was defined more than once in the database!\n");

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

	if (searchDate.compare(startDate) < 0) // before bitcoin creation/data starts
		return (0);
	
	Date tmpDate = db.front();
	double tmpValue = tmpDate.getValue();
	double tmpDist = searchDate.compare(tmpDate);

	for (it = db.begin(); it != db.end(); ++it)
	{
		if (it->compare(searchDate) > 0) // if now is greater than the date to be search or equal it
			break;
			
		if (searchDate.compare(*it) < tmpDist)
		{
			tmpDist = searchDate.compare(*it);
			tmpValue = it->getValue();
			tmpDate = *it;

		}
	}
	tmpDate.print();
	//std::cout << " value found: " << tmpValue << std::endl;
	//std::cout << "\nclosest value is" << tmpValue << " " <<  tmpDist << std::endl;
	return (tmpValue * searchDate.getValue());
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream inFile(DATABASE_FILE);
	startDate = Date("2009-01-02,0", ',');
	
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


/* ------------------------- Other functions from  date -------------------------  */

std::string Date::concatChar(const std::string& s, char c) 
{
    return s + c;
}

std::string Date::trimLeft(const std::string& str) 
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string Date::trimRight(const std::string& str) 
{
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Date::trim(const std::string& str) 
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) return "";
    
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(start, end - start + 1);
}

bool Date::hasOnlyNumbersAndDots(const std::string& str) 
{
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(static_cast<unsigned char>(str[i])) && str[i] != '.') {
            return false;
        }
    }
    return true;
}

int Date::getYear() { return (year); }
int Date::getMonth() { return (month); }
int Date::getDay() { return (day); }
double Date::getValue() { return (value); }

Date::Date() { }

Date::Date(const Date &other)
{
	this->day   = other.day;
	this->month = other.month;
	this->year  = other.year;
	this->value = other.value;
}
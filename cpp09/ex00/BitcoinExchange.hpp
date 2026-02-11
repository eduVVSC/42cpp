/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:48:19 by edvieira          #+#    #+#             */
/*   Updated: 2026/02/11 11:32:34 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <exception>
# include <list>

#include <cstdlib>
#include <climits>
#include <string.h>
#include <cerrno>
#include <algorithm>


# define DATABASE_FILE "data.csv"

# define DAY_MAX 31
# define MONTH_MAX 12
# define YEAR_MAX 2022
# define VALUE_MAX 1000
# define VALUE_MIN 0

class CouldNotOpenFileException : public std::exception
{
private:
    std::string message;
public:
    CouldNotOpenFileException(const std::string& msg) { this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~CouldNotOpenFileException() throw() {}
};

class BadDateException : public std::exception
{
private:
    std::string message;
public:
    BadDateException(const std::string& msg){this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~BadDateException() throw() {}
};

class BadValueException : public std::exception
{
private:
    std::string message;
public:
    BadValueException(const std::string& msg){this->message = msg; }

    virtual const char* what() const throw(){ return this->message.c_str(); }
    virtual ~BadValueException() throw() {}
};


// class will have the responsability to validate the input from the line and throw
// the exception in case the line doesn't follow the requirements
class Date	
{
private:
	int day;
	int year;
	int month;

	double value;

	bool readDate(std::string line);
	bool validDate();

	std::string	trim(const std::string& str);
	std::string	trimLeft(const std::string& str);
	std::string	trimRight(const std::string& str);
	std::string concatChar(const std::string& s, char c);
	bool		hasOnlyNumbersAndDots(const std::string& str);


public:
	int compare(Date &other);

	int getDay();
	int getMonth();
	int getYear();
	double getValue();

	void print();

	Date();
	Date(std::string line, char separator);
	Date(const Date &other);

	Date operator=(const Date &other);   
	
	bool operator==(const Date& other) const;

	~Date();
};

class BitcoinExchange
{
private:
	std::list<Date> db; // hold the read database
	Date startDate;

	double getFullRate(Date searchDate);
	bool valid_Num(std::string line, int i);    // 2nd
	bool valid_Date(std::string line, int which);   // 3rd
	bool valid_Format(std::string line); // 1st
	void readDatabaseValues(std::ifstream& inFile);
public:

	BitcoinExchange();
	void convert(std::string filename);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange operator=(const BitcoinExchange &other);
};

#endif

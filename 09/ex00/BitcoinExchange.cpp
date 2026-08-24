/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:29:56 by yelu              #+#    #+#             */
/*   Updated: 2026/08/11 18:21:47 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadDataFromCSV(const std::string &database)
{
	std::ifstream file(database.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open database file");
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::invalid_argument("Error: Bad or missing header in database file");
	while (std::getline(file, line))
	{
		std::pair<std::string, float> entry;
		if (!parseDatabaseLine(line, entry, ','))
			continue;
		else
		{
			this->_database[entry.first] = entry.second;
		}
	}
	file.close();
	// printDatabase();
}

bool	BitcoinExchange::processInputFile(const std::string &filename)
{
	if (filename.find(".txt") == std::string::npos)
		throw std::invalid_argument("Error: Only .txt file allowed");
	else
	{
		std::ifstream inputFile(filename.c_str());
		if (!inputFile.is_open())
			throw std::runtime_error("Error: Could not open input file");
		std::string line;
		std::getline(inputFile, line);
		if (line != "date | value")
			throw std::invalid_argument("Error: Expected header in input file");
		int i = 1;
		while (std::getline(inputFile, line))
		{
			std::pair<std::string, float> entry;
			if (!parseInputLine(line, entry, '|', i))
			{
				i++;
				continue;
			}
			else
			{
				evaluate(entry.first, entry.second);
				i++;
			}
		}
		inputFile.close();
		return (true);
	}
}

// ================================================================================
// Private member functions
// ================================================================================


void	BitcoinExchange::evaluate(const std::string &date, float value)
{
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	if (it == _database.end())
	{
		--it;
	}
	else if (it->first != date && it != _database.begin())
	{
		--it;
	}
	else if (it->first != date && it == _database.begin())
	{
		std::cerr << "Error: No exchange rate available for date " << date << "\n";
		return ;
	}
	float exchangeRate = it->second;
	double result = value * exchangeRate;
	std::cout << "Exchange rate: " << exchangeRate << "\n";
	std::cout << std::fixed << std::setprecision(2);
	std::cout << date << " => " << value << " = " << result << "\n";
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	const int mnth[] = {
		0, 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	std::stringstream ss(date);
	std::string StrYear, StrMonth, StrDay;
	if (!getline(ss, StrYear, '-') || !getline(ss, StrMonth, '-') || !getline(ss, StrDay))
		return (false);
	int y, m, d;
	std::stringstream ssy;
	std::stringstream ssm;
	std::stringstream ssd;
	ssy << StrYear;
	ssy >> y;
	ssm << StrMonth;
	ssm >> m;
	ssd << StrDay;
	ssd >> d;
	if (y < 1900 || y > 3000 || m < 1 || m > 12)
	{
		return (false);
	}
	int maxDay = mnth[m];
	if ((m == 2 && (y % 4 == 0 && y % 100 != 0)) || (y % 400 == 0))
		maxDay = 29;
	if (d < 1 || d > maxDay)
	{
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string &value)
{
	float fvalue;
	std::stringstream ssvalue;
	ssvalue << value;
	ssvalue >> fvalue;
	if (fvalue > 1000)
	{
		std::cerr << "Error: Value exceeds maximum limit of 1000. ";
		return (false);
	}
	else if (fvalue < 0)
	{
		std::cerr << "Error: Value cannot be negative. ";
		return (false);
	}
	else if (ssvalue.fail() || !ssvalue.eof())
	{
		std::cerr << "Error: Invalid value format. ";
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidDatabaseValue(const std::string &value)
{
	float fvalue;
	std::stringstream ssvalue;
	ssvalue << value;
	ssvalue >> fvalue;
	if (fvalue < 0)
		return (false);
	else if (ssvalue.fail() || !ssvalue.eof())
		return (false);
	return (true);
}


bool	BitcoinExchange::parseDatabaseLine(const std::string &line, std::pair<std::string, float> &entry, char delimiter)
{
		std::string date;
		std::string value;
		std::stringstream ss(line);
		if (!std::getline(ss, date, delimiter) || !std::getline(ss, value))
			return (false);
		if (!isValidDate(date))
			return (false);
		if (!isValidDatabaseValue(value))
			return (false);
		entry.first = date;
		float exchangeRate;
		if (!(std::stringstream(value) >> exchangeRate))
			return (false);
		entry.second = exchangeRate;
		return (true);
}

bool	BitcoinExchange::parseInputLine(const std::string &line, std::pair<std::string, float> &entry, char delimiter, int i)
{
	std::string date;
	std::string value;
	std::stringstream ss(line);
	if (!std::getline(ss, date, delimiter) || !std::getline(ss, value))
	{
		std::cerr << "Error: Invalid line format in input file at line " << i << ": " << line << "\n";
		return (false);
	}
	if (date.empty() || value.empty())
	{
		std::cerr << "Error: Missing date or value in input file at line " << i << ": " << line << "\n";
		return (false);
	}
	if (!isValidDate(date))
	{
		std::cerr << "Error: Invalid date in input file at line " << i << ": " << date << "\n";
		return (false);
	}
	if (!isValidValue(value))
	{
		std::cerr << "Invalid value in input file at line " << i << ": " << value << "\n";
		return (false);
	}
	entry.first = date;
	float exchangeRate;
	if (!(std::stringstream(value) >> exchangeRate))
		return (false);
	entry.second = exchangeRate;
	return (true);
}


void	BitcoinExchange::printDatabase() const
{
	std::map<std::string, float>::const_iterator it = _database.begin();
	while (it != _database.end())
	{
		std::cout << it->first << " => " << it->second << "\n";
		++it;
	}
}

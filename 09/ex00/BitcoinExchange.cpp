/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:29:56 by yelu              #+#    #+#             */
/*   Updated: 2026/08/10 15:52:30 by yelu             ###   ########.fr       */
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
	printDatabase();
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
				std::cout << entry.first << " => " << entry.second << std::endl;
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


bool BitcoinExchange::isValidDate(const std::string &date)
{
	std::stringstream ss(date);
	std::string year, month, day;
	if (!getline(ss, year, '-') || !getline(ss, month, '-') || !getline(ss, day))
		return (false);
	return (true);

}

bool BitcoinExchange::isValidValue(const std::string &value)
{
	(void)value;
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
		if (!isValidValue(value))
			return (false);
		entry.first = date;
		float exchangeRate;
		std::stringstream(value) >> exchangeRate;
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
		std::cerr << "Error: Invalid line format in input file at line " << i << ": " << line << std::endl;
		return (false);
	}
	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input in input file => " << date << " at line " << i << "\n";
		return (false);
	}
	if (!isValidValue(value))
		return (false);
	(void)entry;
	return (true);
}



void	BitcoinExchange::printDatabase() const
{
	std::map<std::string, float>::const_iterator it = _database.begin();
	while (it != _database.end())
	{
		std::cout << it->first << " => " << it->second << std::endl;
		++it;
	}
}

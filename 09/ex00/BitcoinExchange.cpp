/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:29:56 by yelu              #+#    #+#             */
/*   Updated: 2026/08/04 14:55:51 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::parseLine(std::string line)
{
	(void)line;
	std::cout << "Hello\n";
	return (true);
}

bool	BitcoinExchange::processInputFile(const std::string &filename)
{
	if (filename.find(".txt") == std::string::npos)
	{
		std::cerr << "Error: Input file must be a .txt file\n";
		return (false);
	}
	else
	{
		std::ifstream inputFile(filename.c_str());
		if (!inputFile.is_open())
		{
			std::cerr << "Error: Could not open input file\n";
			return (false);
		}
		std::string line;
		while (std::getline(inputFile, line))
		{
			if (!parseLine(line))
				return (false);
		}
		inputFile.close();
		return (true);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:30:07 by yelu              #+#    #+#             */
/*   Updated: 2026/08/10 15:45:11 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <ostream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		std::map<std::string, float> _database;
		bool	parseDatabaseLine(const std::string &line, std::pair<std::string, float> &entry, char delimiter);
		bool	parseInputLine(const std::string &line, std::pair<std::string, float> &entry, char delimiter, int i);
		bool	isValidDate(const std::string &date);
		bool	isValidValue(const std::string &value);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	loadDataFromCSV(const std::string &database);
		bool	processInputFile(const std::string &filename);
		void	printDatabase() const;

};

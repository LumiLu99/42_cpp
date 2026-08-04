/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:30:07 by yelu              #+#    #+#             */
/*   Updated: 2026/08/04 14:54:49 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		std::map<std::string, double> _data;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		bool	processInputFile(const std::string &filename);
		bool	parseLine(std::string line);
		
};

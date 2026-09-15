/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:29:54 by yelu              #+#    #+#             */
/*   Updated: 2026/08/05 12:21:12 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange btc;
			btc.loadDataFromCSV("data.csv");
			btc.processInputFile(argv[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << "\n";
			return (1);
		}
	}
	else
		std::cerr << "Error: Usage: ./bitcoin <input_file>\n";
}

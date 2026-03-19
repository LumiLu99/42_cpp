/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:36:49 by yelu              #+#    #+#             */
/*   Updated: 2026/03/04 21:36:49 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{ 
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printChar(double value, bool isSpecial)
{
	std::cout << "char: ";
	if (isSpecial || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable character" << std::endl;
}

void ScalarConverter::printInt(double value, bool isSpecial)
{
	std::cout << "int: ";
	if (isSpecial || value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
	else
	{
		// fixed defaults to 6 decimal places
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& argv)
{
	double	value;
	char	*end;
	bool	isSpecial;

	if (argv.length() == 1 && !std::isdigit(argv[0]))
	{
		value = static_cast<double>(argv[0]);
	}
	else
	{
		value = std::strtod(argv.c_str(), &end);
		isSpecial = std::isnan(value) || std::isinf(value);
	}

	printChar(value, isSpecial);
	printInt(value, isSpecial);
	printFloat(value);
	printDouble(value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:36:49 by yelu              #+#    #+#             */
/*   Updated: 2026/07/14 19:18:09 by yelu             ###   ########.fr       */
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

void ScalarConverter::printChar(double value, bool isSpecial, bool isImpossible)
{
	std::cout << "char: ";
	if (isImpossible || isSpecial || value < 0 || value > 127)
		std::cout << "impossible\n";
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'\n";
	else
		std::cout << "Non displayable character\n";
}

void ScalarConverter::printInt(double value, bool isSpecial, bool isImpossible)
{
	std::cout << "int: ";
	if (isImpossible || isSpecial || value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";
}

void ScalarConverter::printFloat(double value, bool isImpossible)
{
	std::cout << "float: ";
	if (isImpossible)
		std::cout << "impossible\n";
	else if (std::isnan(value))
		std::cout << "nanf\n";
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inff" : "+inff") << "\n";
	else
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
	}
}

void ScalarConverter::printDouble(double value, bool isImpossible)
{
	std::cout << "double: ";
	if (isImpossible)
		std::cout << "impossible\n";
	else if (std::isnan(value))
		std::cout << "nan\n";
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inf" : "+inf") << "\n";
	else
		std::cout << std::fixed << std::setprecision(1) << value << "\n";
}

void ScalarConverter::convert(const std::string& argv)
{
	double	value = 0.0;
	char	*end = NULL;
	bool	isSpecial = false;
	bool	isImpossible = false;

	if (argv.length() == 1 && !std::isdigit(argv[0]))
	{
		value = static_cast<double>(argv[0]);
	}
	else
	{
		value = std::strtod(argv.c_str(), &end);

		// If nothing was parsed, OR there are invalid trailing characters
		if (end == argv.c_str() || (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')))
		{
			isImpossible = true;
		}
		else
		{
			isSpecial = std::isnan(value) || std::isinf(value);
		}
	}
	printChar(value, isSpecial, isImpossible);
	printInt(value, isSpecial, isImpossible);
	printFloat(value, isImpossible);
	printDouble(value, isImpossible);
}

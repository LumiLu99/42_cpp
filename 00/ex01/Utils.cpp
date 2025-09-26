/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:13:44 by yelu              #+#    #+#             */
/*   Updated: 2025/09/26 20:18:37 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

std::string Formatting(const std::string &str)
{
	if (str.length() > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	else
		return (str);
}

int isValidInput(const std::string &str)
{
	int length = str.length();
	if (length != 1)
		return (0);
	if (!std::isdigit(str[0]))
		return (0);
	if (str[0] < '0' || str[0] > '7')
		return (0);
	return (1);
}

int strToInt(const std::string &str)
{
	return atol(str.c_str());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:13:44 by yelu              #+#    #+#             */
/*   Updated: 2025/09/26 16:47:04 by yelu             ###   ########.fr       */
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

int IsNumber(const std::string &str)
{
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int strToInt(const std::string &str)
{
	return atoi(str.c_str());
}

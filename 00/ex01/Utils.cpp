/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:13:44 by yelu              #+#    #+#             */
/*   Updated: 2025/09/26 14:27:25 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string Formatting (const std::string &str)
{
	if (str.length() > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	else
		return (str);
}

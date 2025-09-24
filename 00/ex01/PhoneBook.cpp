/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:06:27 by yelu              #+#    #+#             */
/*   Updated: 2025/09/24 13:47:43 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
	Contact c;
	std::string input;

	while (1)
	{
		std::cout << "Please enter First Name: ";
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
		if (input.empty())
		{
			std::cout << "Field cannot be empty\n";
			continue ;
		}
		else
		{
			c.setFirstName(input);
			break ;
		}
	}
	if (_count < 8)
	{
		_contact[_count] = c;
		_count++;
	}
	else
	{
		_contact[_count % 8] = c;
		_count++;
	}
	std::cout << "Contact saved: " << c.getFirstName() << "\n";
	return ;
}

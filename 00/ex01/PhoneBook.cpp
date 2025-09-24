/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:06:27 by yelu              #+#    #+#             */
/*   Updated: 2025/09/24 16:03:18 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
	Contact c;
	std::string input;
	const std::string field[5] = 
	{
		"first name",
		"Last Name",
		"Nickname",
		"Phone Number",
		"Darkest Secret",
	};

	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << "Please enter " << field[i] << ": ";
			if (!std::getline(std::cin, input))
			{
				std::cout << "\n";
				std::cout << RED << " Force exiting the program...\n" << RESET;
				exit(EXIT_SUCCESS);
			}
			if (input.empty())
			{
				std::cout << RED << BOLD << "Field cannot be empty\n" << RESET;
				continue ;
			}
			if (i == 0)
				c.setFirstName(input);
			else if (i == 1)
				c.setLastName(input);
			else if (i == 2)
				c.setNickname(input);
			else if (i == 3)
				c.setPhoneNumber(input);
			else if (i == 4)
				c.setDarkSecret(input);
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
	std::cout << GREEN << "Contact \"" << c.getFirstName() << "\" saved.\n" << RESET;
	return ;
}

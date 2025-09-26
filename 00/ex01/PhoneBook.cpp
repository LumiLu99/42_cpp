/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:06:27 by yelu              #+#    #+#             */
/*   Updated: 2025/09/26 20:26:35 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

std::string Formatting (const std::string &str);
int isValidInput(const std::string &str);
int strToInt(const std::string &str);

PhoneBook::PhoneBook()
{
	_count = 0;
}

void PhoneBook::addContact()
{
	Contact c;
	std::string input;

	const std::string field[5] = 
	{
		"First Name",
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
				std::cout << RED << "Error. Force exiting the program...\n" << RESET;
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
		std::cout << "\nContact[" << _count << "] "; 
		_contact[_count] = c;
		_count++;
	}
	else
	{
		_count = _count % 8;
		_contact[_count] = c;
		std::cout << "Contact[" << _count << "] ";
		_count++;
	}
	std::cout << GREEN << "\"" << c.getFirstName() << "\" saved.\n\n" << RESET;
	return ;
}

void PhoneBook::searchContact()
{
	std::string input;

	while (1)
	{
		if (!listContact())
			return ;
		std::cout << GREEN << "\nEnter \"BACK\" to go back to main menu.\n" << RESET;
		std::cout << BOLD << "\nEnter index number of contact to display (0-7): " << RESET;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\n";
			std::cout << RED << "Error. Force exiting the program...\n" << RESET;
			exit(EXIT_SUCCESS);
		}
		if (input.empty())
		{
			std::cout << RED << "Input cannot be empty. Please enter a valid command.\n\n" << RESET;
			continue;
		}
		if (input == "BACK")
		{
			std::cout << GREEN << "\nReturning...\n" << RESET;
			return ;
		}
		else
		{
			if (!validateContact(input))
			{
				std::cout << RED << "\nInvalid or wrong input. Please enter only valid index without spaces.\n\n" << RESET;
				continue;
			}
			else
				continue;
		}
		break ;
	}
	return ;
}

int PhoneBook::listContact()
{
	if (_count == 0)
	{
		std::cout << RED << "\nPhone Book is empty! Add your contacts through the main menu.\n" << RESET;
		std::cout << RED << "Returning...\n\n" << RESET;
		return (0);
	}

	const std::string Column[4] =
	{
		"Index",
		"First Name",
		"Last Name",
		"Nickname",
	};

	for (int i = 0; i < 4; i++)
		std::cout << std::setw(10) << std::right << Column[i] << "|";
	std::cout << "\n";
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right 
		<< Formatting(_contact[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right 
		<< Formatting(_contact[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right 
		<< Formatting(_contact[i].getNickname()) << "|";
		std::cout << "\n";
	}
	return (1);
}

int PhoneBook::validateContact(const std::string &str)
{
	int i;

	if (!isValidInput(str))
		return (0);
	else 
		i = atoi(str.c_str());
	std::cout << "What is in i: " << i << "\n";
	std::cout << "First Name: " << _contact[i].getFirstName() << "\n";
	std::cout << "Last Name: " << _contact[i].getLastName() << "\n";
	std::cout << "Nickname: " << _contact[i].getNickname() << "\n";
	std::cout << "Phone Number: " << _contact[i].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret:" << _contact[i].getDarkSecret() << "\n";
	std::cout << GREEN << "\nReturning...\n\n" << RESET;
	return (1);
}

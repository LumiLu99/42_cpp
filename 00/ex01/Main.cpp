/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:27:22 by yelu              #+#    #+#             */
/*   Updated: 2025/09/27 15:00:22 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

enum Command
{
	ADD,
	SEARCH,
	EXIT,
	INVALID
};

static Command convertCmd(const std::string &input)
{
	if (input == "ADD")
		return (ADD);
	else if (input == "SEARCH")
		return (SEARCH);
	else if (input == "EXIT")
		return (EXIT);
	else
		return (INVALID);
}

static int executeCommand(Command cmd, PhoneBook &pb)
{
	switch (cmd)
	{
		case ADD:
			pb.addContact();
			break;
		case SEARCH:
			pb.searchContact();
			break;
		case EXIT:
			std::cout << RED << "\nExiting the program...\n" << RESET;
			return (0);
		case INVALID:
			std::cout << RED << "\nInvalid command. Please enter only ADD, SEARCH and EXIT without spaces.\n\n" << RESET;
			break;
	}
	return (1);
}

int main()
{
	PhoneBook pb;
	std::string input;
	int status = 1;

	system("clear");
	while (status)
	{
		std::cout << CYAN << "=====================================\n" << RESET;
		std::cout << BOLD << YELLOW << "      AWESOME CRAPPY PHONEBOOK       \n" << RESET;
		std::cout << CYAN << "=====================================\n"	<< RESET;
		std::cout << GREEN << " Welcome to awesome crappy phonebook!\n" << RESET;
		std::cout << BLUE << " ADD: " << RESET << "Add Contact\n";
		std::cout << MAGENTA << " SEARCH: " << RESET << "Search Contact\n";
		std::cout << RED << " EXIT: " << RESET << "Exit the program\n";
		std::cout << CYAN << "=====================================\n" << RESET;
		std::cout << YELLOW << " Type your commands in UPPERCASE words and without spaces!\n" << RESET;
		std::cout << "\n";
		std::cout << BOLD << " Please enter your choice: " << RESET;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\n";
			std::cout << RED << "Error. Force exiting the program...\n" << RESET;
			exit(EXIT_SUCCESS);
		}
		if (input.empty())
		{
			system("clear");
			std::cout << RED << "Input cannot be empty. Please enter a valid command.\n\n" << RESET;
			continue;
		}
		else
		{
			system("clear");
			status = executeCommand(convertCmd(input), pb);
		}
	}
	return (0);
}

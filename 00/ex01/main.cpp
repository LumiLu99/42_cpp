/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:27:22 by yelu              #+#    #+#             */
/*   Updated: 2025/09/09 22:07:12 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pb.hpp"

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

static int executeCommand(Command cmd)
{
	switch (cmd)
	{
	case ADD:
		std::cout << "You chose to ADD a contact.\n";
		addContact();
		break;
	case SEARCH:
		std::cout << "You chose to SEARCH for a contact.\n";
		break;
	case EXIT:
		std::cout << "Exiting the program...\n";
		return (0);
	case INVALID:
		std::cout << RED << "Invalid command. Please enter only ADD, SEARCH and EXIT.\n\n" << RESET;
		break;
	}
	return (1);
}

int main()
{
	std::string input;
	int status = 1;

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
		std::cout << YELLOW << " Type your commands in UPPERCASE words only!\n" << RESET;
		std::cout << "\n";
		std::cout << BOLD << " Please enter your choice: " << RESET;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << RED << "Input cannot be empty. Please enter a valid command.\n\n" << RESET;
			continue;
		}
		else
		{
			std::cout << "You entered: " << input << std::endl;
			status = executeCommand(convertCmd(input));
		}
	}
}

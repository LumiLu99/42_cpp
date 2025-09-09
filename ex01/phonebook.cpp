/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:27:22 by yelu              #+#    #+#             */
/*   Updated: 2025/09/08 18:35:27 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cout << "Welcome to the crappy awesome phonebook software!" << std::endl;
	std::cout << "Please enter a command (ADD, SEARCH, DELETE, EXIT): ";
	std::cin >> input;

	std::cout << "You entered: " << input << std::endl;
}

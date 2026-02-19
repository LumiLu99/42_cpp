/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:56:30 by yelu              #+#    #+#             */
/*   Updated: 2026/02/12 22:58:21 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\n=== Create bob object with 0 grade ===\n";
		try
		{
			Bureaucrat bob("Bob", 0);
		}
		catch (const std::exception &error)
		{
			std::cerr << "Error: " << error.what() << " \n";
		}
	}

	{
		std::cout << "\n=== Create bob object with 151 grade ===\n";
		try
		{
			Bureaucrat bob("Bob", 151);
		}
		catch (const std::exception &error)
		{
			std::cerr << "Error: " << error.what() << " \n";
		}
	}

	{
		std::cout << "\n=== Create bob object with 75 grade ===\n";
		try
		{
			Bureaucrat bob("Bob", 75);
			std::cout << "Bureaucrat " << bob.getName() << " with grade " << bob.getGrade() << " created!\n";
		}
		catch (const std::exception &error)
		{
			std::cerr << "Error: " << error.what() << " \n";
		}
	}

	{
		std::cout << "\n=== Operator << overload test ===\n";
		try
		{
			Bureaucrat bob("Bob", 42);
			std::cout << bob << "\n";
		}
		catch (const std::exception &error)
		{
			std::cerr << "Error: " << error.what() << " \n";
		}
	}
}

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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "\n== Can Grade 145 Bob sign form 145 grade? ==\n";
		Bureaucrat bob("Bob", 145);
		ShrubberyCreationForm form("bush");
		form.signForm(bob);
		std::cout << form.getName() << " is signed: " << std::boolalpha << form.getIsSigned() << "\n";
		bob.executeForm(form);
	}
	{
		std::cout << "\n== Can Grade 134 Bob sign form 135 grade? ==\n";
		Bureaucrat bob("Bob", 134);
		ShrubberyCreationForm form("bush");
		form.signForm(bob);
		std::cout << form.getName() << " is signed: " << std::boolalpha << form.getIsSigned() << "\n";
		bob.executeForm(form);
	}
	{
		std::cout << "\n== Can Grade 150 Bob sign form 145 grade? ==\n";
		Bureaucrat bob("Bob", 150);
		ShrubberyCreationForm form("bush");
		form.signForm(bob);
		std::cout << form.getName() << " is signed: " << std::boolalpha << form.getIsSigned() << "\n";
		bob.executeForm(form);
	}
}

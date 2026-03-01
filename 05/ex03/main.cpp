/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:56:30 by yelu              #+#    #+#             */
/*   Updated: 2026/03/01 19:09:10 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "\n== Can Grade 145 Bob sign form 145 grade? ==\n";
		Bureaucrat bob("Bob", 145);
		ShrubberyCreationForm form("tree");
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

	{
		std::cout << "\n== Robotomize test == \n";
		Bureaucrat bob("Bob", 150);
		Bureaucrat lydia("Lydia", 34);
		RobotomyRequestForm form("Skeletron");
		form.signForm(bob);
		form.signForm(lydia);
		std::cout << form.getName() << " is signed: " << std::boolalpha << form.getIsSigned() << "\n";
		bob.executeForm(form);
		lydia.executeForm(form);
		bob = lydia;
		form.signForm(bob);
		bob.executeForm(form);
	}
	{
		std::cout << "\n== President Pardon test ==\n";
		Bureaucrat trump("President Trump", 1);
		Bureaucrat bob("Bob", 34);
		PresidentialPardonForm form("Elon Musk");
		form.signForm(bob);
		form.signForm(trump);
		std::cout << form.getName() << " is signed: " << std::boolalpha << form.getIsSigned() << "\n";
		bob.executeForm(form);
		trump.executeForm(form);
	}
}

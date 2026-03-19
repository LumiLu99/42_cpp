/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:56:30 by yelu              #+#    #+#             */
/*   Updated: 2026/03/04 17:18:21 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat trump("President Trump", 1);
	Bureaucrat bob("Bob", 150);

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rrf)
	{
		try
		{
				rrf->signForm(bob);
				rrf->signForm(trump);
				rrf->execute(bob);
				rrf->execute(trump);

		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
		delete rrf;
	}

	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (scf)
	{
		try
		{
			scf->signForm(trump);
			scf->execute(trump);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
		delete scf;
	}

	AForm* unknown = someRandomIntern.makeForm("coffee request", "Intern");
	if (unknown)
	{
		delete unknown;
	}
	else if (!unknown)
	{
		std::cout << "Coffee request is NULL.\n";
	}
}

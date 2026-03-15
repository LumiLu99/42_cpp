/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:56:30 by yelu              #+#    #+#             */
/*   Updated: 2026/03/02 18:51:34 by yelu             ###   ########.fr       */
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
	Bureaucrat trump("Trump", 1);
	Bureaucrat bob("Bob", 150);

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Bob Ross");
	
	if (rrf) {
		rrf->signForm(trump);
		trump.executeForm(*rrf);
		bob.executeForm(*rrf);
		delete rrf;
	}
	if (pardon) {
		pardon->signForm(trump);
		trump.executeForm(*pardon);
		bob.executeForm(*pardon);
		delete pardon;
	}

	AForm* unknown = someRandomIntern.makeForm("coffee request", "Intern");
	if (unknown) {
		delete unknown;
	}
}
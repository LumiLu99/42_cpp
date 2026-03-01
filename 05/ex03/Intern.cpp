/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:21:05 by yelu              #+#    #+#             */
/*   Updated: 2026/03/01 22:10:04 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern()
{
	// std::cout << "Intern default constructor called!\n";
}

Intern::Intern(const Intern &other)
{
	// std::cout << "Intern copy constructor called!\n";
}

Intern &Intern::operator=(const Intern &other)
{
	return (*this);
}

Intern::~Intern()
{
	// std::cout << "Intern deconstructor called!\n";
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

	for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << " \n";
            return (this->*formCreators[i])(target);
        }
    }

    std::cout << "Error: Intern cannot create " << formName << " because it doesn't exist." << std::endl;
    return NULL;
}
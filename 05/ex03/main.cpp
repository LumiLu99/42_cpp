/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:56:30 by yelu              #+#    #+#             */
/*   Updated: 2026/03/01 22:03:39 by yelu             ###   ########.fr       */
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

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    if (rrf) {
        // Do something with the form
        delete rrf; // Crucial! The Intern allocated this with 'new'
    }

    // Test a failure case
    AForm* unknown = someRandomIntern.makeForm("coffee request", "Intern");
    if (!unknown) {
        // This will correctly handle the NULL return
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-19 11:04:18 by yelu              #+#    #+#             */
/*   Updated: 2026-02-19 11:04:18 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    // std::cout << "ShrubberyCreationForm constructor called" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
    // std::cout << "ShrubberyCreationForm copy constructor called" << "\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    // std::cout << "ShrubberyCreationForm copy assignment operator called" << "\n";
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "ShrubberyCreationForm destructor called" << "\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream outFile(_target + "_shrubbery");
    if (!outFile)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }

    outFile << "       _-_" << std::endl;
    outFile << "    /~~   ~~\\" << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
}
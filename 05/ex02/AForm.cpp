/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-19 05:13:55 by yelu              #+#    #+#             */
/*   Updated: 2026-02-19 05:13:55 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm parameterized constructor called!\n";
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	// std::cout << "AForm copy constructor called!\n";
}

AForm &AForm::operator=(const AForm &other)
{
	// std::cout << "AForm copy assignment operator called!\n";
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called!\n";

}

const std::string &AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

const int &AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

const int &AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

void AForm::signForm(const Bureaucrat &bureaucrat)
{
	try
	{
		this->beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signed " << this->getName() << "\n";
	}
	catch (const std::exception &error)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because " << error.what() << "\n";
	}
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << "Form Name: " << src.getName() << "\n";
	out << "Signed: " << (src.getIsSigned() ? "Yes" : "No") << "\n";
	out << "Grade Required to Sign: " << src.getGradeToSign() << "\n";
	out << "Grade Required to Execute: " << src.getGradeToExecute() << "\n";
	return (out);
}

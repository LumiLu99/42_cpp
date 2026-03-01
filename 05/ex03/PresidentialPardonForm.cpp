/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:36:39 by yelu              #+#    #+#             */
/*   Updated: 2026/03/01 19:08:25 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("President Pardon Form", 25, 5), _target(target)
{
	// std::cout << "President Pardon Form default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	// std::cout << "President Pardon Form copy constructor called\n";
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Presidential Pardon Form deconstructor called.\n";
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
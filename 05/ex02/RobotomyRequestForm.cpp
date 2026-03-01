/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:12:57 by yelu              #+#    #+#             */
/*   Updated: 2026/03/01 18:56:04 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	// std::cout << "Robotomy Creation Form constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	// std::cout << "Robotomy Creation Form copy constructor called.\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Robotomy Request Form destructor called.\n";
}


const std::string &RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	static bool seeded = false;

    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
	std::cout << "DRIIIIILLLLLLLLLLLLLLL NOISES\n";
    if (std::rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully 50% of the time.\n";
    else
        std::cout << "Robotomy failed.\n";
}

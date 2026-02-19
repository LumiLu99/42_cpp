/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:37:12 by yelu              #+#    #+#             */
/*   Updated: 2026/02/12 22:37:12 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	// std::cout << "Bureaucrat " << _name << " with grade " << _grade << " created!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	// std::cout << "Bureaucrat copy constructor called!\n";
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	// std::cout << "Bureaucrat copy assignment operator called!\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat destructor called!\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	// std::cout << "Bureaucrat parameterized constructor called!\n";
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

const int &Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "\n";
	out << "--- [Personnel File] ---\n";
	out << "Name: " << src.getName() << "\n";
	out << "Rank: " << src.getGrade() << "\n";
	out << "Status: Overworked";
	return (out);
}

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

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	// std::cout << "Bureaucrat parameterized constructor called!\n";
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name),
	_grade(other._grade)
{
	// std::cout << "Bureaucrat copy constructor called!\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	// std::cout << "Bureaucrat copy assignment operator called!\n";
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat destructor called!\n";
}


const std::string &Bureaucrat::getName() const
{
	return (_name);
}

const int &Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::PromoteGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::DemoteGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "\n";
	out << "--- [Personnel File] ---\n";
	out << "Name: " << src.getName() << "\n";
	out << "Rank: " << src.getGrade() << "\n";
	out << "Status: 做牛做马🐎";
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high for Bureacrat. Enter a grade between 1 and 150.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low for Bureacrat. Enter a grade between 1 and 150.");
}


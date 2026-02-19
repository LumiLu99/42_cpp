/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:40:38 by yelu              #+#    #+#             */
/*   Updated: 2026/02/12 22:40:38 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(std::string name, int grade);

		const std::string &getName() const;
		const int &getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too high. Enter a grade between 1 and 150.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too low. Enter a grade between 1 and 150.");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif
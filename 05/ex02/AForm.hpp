/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-19 05:13:58 by yelu              #+#    #+#             */
/*   Updated: 2026-02-19 05:13:58 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string   _name;
		bool                _isSigned;
		const int           _gradeToSign;
		const int           _gradeToExecute;
	
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const std::string &getName() const;
		bool getIsSigned() const;
		const int &getGradeToSign() const;
		const int &getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void signForm(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};
	
std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-19 05:13:58 by yelu              #+#    #+#             */
/*   Updated: 2026-02-19 05:13:58 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string   _name;
		bool                _isSigned;
		const int           _gradeToSign;
		const int           _gradeToExecute;
	
	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string &getName() const;
		bool getIsSigned() const;
		const int &getGradeToSign() const;
		const int &getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void signForm(const Bureaucrat &bureaucrat);
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
	
std::ostream &operator<<(std::ostream &out, const Form &src);

#endif
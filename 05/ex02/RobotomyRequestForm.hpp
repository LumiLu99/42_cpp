/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:12:51 by yelu              #+#    #+#             */
/*   Updated: 2026/03/01 17:02:57 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include "AForm.hpp"
#include <ctime> // time
#include <cstdlib> // rand, srand

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		const std::string &getTarget() const;

		void execute(const Bureaucrat &executor) const;
};


#endif
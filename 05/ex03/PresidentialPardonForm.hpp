/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:36:42 by yelu              #+#    #+#             */
/*   Updated: 2026/03/01 18:06:20 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENT_PARDON_HPP
#define PRESIDENT_PARDON_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		const std::string &getTarget() const;

		void execute(const Bureaucrat &executor) const;
};

#endif
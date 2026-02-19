/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:56:30 by yelu              #+#    #+#             */
/*   Updated: 2026/02/12 22:58:21 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "\n== Can Grade 75 Bob sign form 50 grade? ==\n";
		Bureaucrat bob("Bob", 75);
		Form form("Form A", 50, 25);
		form.signForm(bob);
		std::cout << form.getName() << " is signed: " << std::boolalpha << form.getIsSigned() << "\n";
	}

	{
		std::cout << "\n== Can Grade 75 Bob sign form 100 grade? ==\n";
		Bureaucrat bob("Bob", 75);
		Form form("GongXiFaCai", 100, 25);
		form.signForm(bob);
		std::cout << form.getName() << " is signed: " << std::boolalpha << form.getIsSigned() << "\n";
	}
}

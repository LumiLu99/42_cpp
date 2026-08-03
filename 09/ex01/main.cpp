/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:41 by yelu              #+#    #+#             */
/*   Updated: 2026/08/03 16:10:08 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN rpn;
		rpn.parseNotations(argv);
		return (0);
	}
	else
		std::cout << "Usage: ./RPN <arguments>" << "\n";
}

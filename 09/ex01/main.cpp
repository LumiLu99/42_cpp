/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:41 by yelu              #+#    #+#             */
/*   Updated: 2026/07/30 17:20:38 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc > 2 && argc < 10)
	{
		RPN rpn;
		rpn.parseNotations(argc, argv);
	}
	std::cout << "Usage: ./RPN <arguments>" << "\n";
}

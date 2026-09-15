/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:41 by yelu              #+#    #+#             */
/*   Updated: 2026/08/04 14:33:03 by yelu             ###   ########.fr       */
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
		std::cout << "Usage: ./RPN <arguments> (ie: '8 9 +')" << "\n";
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2) {
// 		std::cerr << "Usage: ./RPN <arguments> (ie: 9 8 + 2)" << "\n";
// 	}
// 	RPN rpn;
// 	try {
// 		rpn.parseNotations(argv);
// 	}
// 	catch(const std::exception& e) {
// 		std::cerr << e.what() << '\n';
// 	}
// 	return (0);
// }

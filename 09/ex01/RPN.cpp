/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:43 by yelu              #+#    #+#             */
/*   Updated: 2026/07/30 20:04:22 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	
}
RPN::RPN(const RPN &other) : _num(other._num) {}
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_num = other._num;
	}
	return (*this);
}

RPN::~RPN() {}

void RPN::parseNotations(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			_num.push(std::atoi(argv[i]));
		}
		else if (argv[i] == "+" || argv[i] == "-" || argv[i] == "*" || argv[i] == "/")
		{
			if (_num.size() < 2)
			{
				std::cout << "Error: Not enough operands for operation." << "\n";
				return ;
			}
		}
	}
}
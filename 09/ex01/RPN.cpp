/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:43 by yelu              #+#    #+#             */
/*   Updated: 2026/07/30 19:54:18 by yelu             ###   ########.fr       */
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
		if (argv[i][0] >= '0' && argv[i][0] <= '9')
		{
			
		}
	}
}
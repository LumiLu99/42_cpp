/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:43 by yelu              #+#    #+#             */
/*   Updated: 2026/08/03 17:14:01 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

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

bool	RPN::performOperation(char input, int *result)
{
	int rhs = _num.top();
	_num.pop();
	int lhs = _num.top();
	_num.pop();
	if (input == '+')
	{
		*result = lhs + rhs;
		return (true);
	}
	else if (input == '-')
	{
		*result = lhs - rhs;
		return (true);
	}
	else if (input == '*')
	{
		*result = lhs * rhs;
		return (true);
	}
	else if (input == '/')
	{
		if (rhs == 0)
		{
			std::cerr << "Error: Division by zero\n";
			return (0);
		}
		*result = lhs / rhs;
		return (true);
	}
	else
	{
		std::cerr << "Error: Invalid operator\n";
		return (false);
	}
}

void RPN::parseNotations(char **argv)
{
	std::string input(argv[1]);
	int result = 0;
	size_t i = 0;

	for (i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			continue ;
		else if (input[i] >= '0' && input[i] <= '9')
		{
			std::string token;
			while (i < input.length() && input[i] >= '0' && input[i] <= '9')
			{
				token += input[i];
				if (token.length() > 1)
				{
					std::cerr << "Error: Only single digit allowed\n";
					return ;
				}
				i++;
			}
			_num.push(std::atoi(token.c_str()));
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (_num.size() < 2)
			{
				std::cout << "Error: Not enough operands for operation\n";
				return ;
			}
			if (performOperation(input[i], &result))
			{
				_num.push(result);
			}
			else
			{
				return ;
			}
		}
		else
		{
			std::cerr << "Error: Invalid character in input\n";
			std::cerr << "Only number 0-9, +, -, *, / operators are allowed\n";
			return ;
		}
	}
	if (_num.size() > 1)
	{
		std::cerr << "Error: More than one elements still in stack\n";
		return ;
	}
	std::cout << _num.top() << "\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:43 by yelu              #+#    #+#             */
/*   Updated: 2026/08/04 14:36:56 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN() {}

bool	RPN::performOperation(char input, int *result)
{
	int rhs = _stack.top();
	_stack.pop();
	int lhs = _stack.top();
	_stack.pop();
	switch (input)
	{
		case ('+'):
		{
			*result = lhs + rhs;
			return (true);
		}
		case ('-'):
		{
			*result = lhs - rhs;
			return (true);
		}
		case ('*'):
		{
			*result = lhs * rhs;
			return (true);
		}
		case ('/'):
		{
			if (rhs == 0)
			{
				std::cerr << "Error: Division by zero\n";
				return (0);
			}
			*result = lhs / rhs;
			return (true);
		}
		default:
		{
			std::cerr << "Error: Invalid operator\n";
			return (false);
		}
	}
}

void RPN::parseNotations(char **argv)
{
	std::stringstream ss(argv[1]);
	std::string token;
	int result = 0;

	while (ss >> token)
	{
		if (token.length() != 1)
		{
			std::cerr << "Error: Invalid RPN syntax. Usage: ./RPN \"<RPN expression>\" (ie: '8 9 +')\n";
			return ;
		}
		if (token[0] >= '0' && token[0] <= '9')
		{
			_stack.push(std::atoi(token.c_str()));
		}
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: Not enough operands for operation\n";
				return ;
			}
			if (performOperation(token[0], &result))
			{
				_stack.push(result);
			}
			else
			{
				std::cerr << "Invalid operations\n";
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
	// if (!ss.eof())
	// {
	// 	std::cerr << "Error: Invalid RPN syntax\n";
	// 	return ;
	// }
	if (_stack.size() > 1)
	{
		std::cerr << "Error: More than one elements still in stack\n";
		return ;
	}
	std::cout << _stack.top() << "\n";
}

// bool	RPN::performOperation(char input, int *result)
// {
// 	int rhs = _stack.top();
// 	_stack.pop();
// 	int lhs = _stack.top();
// 	_stack.pop();
// 	if (input == '+')
// 	{
// 		*result = lhs + rhs;
// 		return (true);
// 	}
// 	else if (input == '-')
// 	{
// 		*result = lhs - rhs;
// 		return (true);
// 	}
// 	else if (input == '*')
// 	{
// 		*result = lhs * rhs;
// 		return (true);
// 	}
// 	else if (input == '/')
// 	{
// 		if (rhs == 0) {
// 			throw std::runtime_error("Error: Division by zero\n");
// 		}
// 		*result = lhs / rhs;
// 		return (true);
// 	}
// 	else
// 		throw std::runtime_error("Error: Invalid operator\n");
// }


// void RPN::parseNotations(char **argv)
// {
// 	std::string input(argv[1]);
// 	int result = 0;
// 	size_t i = 0;

// 	for (i = 0; i < input.size(); i++)
// 	{
// 		if (input[i] == ' ')
// 			continue ;
// 		else if (input[i] >= '0' && input[i] <= '9')
// 		{
// 			std::string token;
// 			while (i < input.length() && input[i] >= '0' && input[i] <= '9')
// 			{
// 				token += input[i];
// 				if (token.length() > 1)
// 					throw std::runtime_error("Error: Only single digit operations allowed\n");
// 				i++;
// 			}
// 			_stack.push(std::atoi(token.c_str()));
// 		}
// 		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
// 		{
// 			if (_stack.size() < 2)
// 				throw std::runtime_error("Error: Not enough numbers for operations.");
// 			if (performOperation(input[i], &result))
// 			{
// 				_stack.push(result);
// 			}
// 			else
// 			{
// 				return ;
// 			}
// 		}
// 		else
// 			throw std::runtime_error("Error: Invalid character in input. Only number 0-9, +, -, *, / operators are allowed\n");
// 	}
// 	if (_stack.size() > 1)
// 		throw std::runtime_error("Error: Invalid RPN syntax. More than one number in stack.\n");
// 	std::cout << _stack.top() << "\n";
// }


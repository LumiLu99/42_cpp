/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:07:45 by yelu              #+#    #+#             */
/*   Updated: 2026/08/04 14:52:56 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

class RPN
{
	private:
		std::stack<int> _stack;
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

	public:
		RPN();
		~RPN();
		void	parseNotations(char **argv);
		bool	performOperation(char input, int *result);
};


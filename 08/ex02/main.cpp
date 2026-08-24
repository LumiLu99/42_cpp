/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:33:19 by yelu              #+#    #+#             */
/*   Updated: 2026/07/28 19:13:50 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	s.push(25);
	std::cout << s.top() << std::endl;
	std::cout << s.size() << std::endl;
	// Stack can use push, pop, top, size, empty, swap, emplace (constract an element directly on top)
	// MutantStack<int>::iterator st = s.begin(); // cannot use std::stack<int>::iterator because std::stack does not have iterators
	// MutantStack<int>::iterator ste = s.end();
	// ++st;
	// --st;
	// while (st != ste)
	// {
	// 	std::cout << *st << std::endl;
	// 	++st;
	// }
	return (0);
}

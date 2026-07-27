/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:26:37 by yelu              #+#    #+#             */
/*   Updated: 2026/03/24 17:27:55 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int main()
{
	{
		std::cout << "== subject pdf test ==\n";
		Span sp = Span(5);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "\n\n == Test 20000 numbers ==\n";
		Span sp(20000);
		std::vector<int> vec(20000);

		std::srand(time(NULL));
		for (unsigned int i = 0; i < 20000; i++)
		{
			vec[i] = std::rand();
		}

		try
		{
			sp.addNumber(vec.begin(), vec.end());
			std::cout << "Shortest Span: " << sp.shortestSpan() << "\n";
			std::cout << "Longest Span: " << sp.longestSpan() << "\n";
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
	}

	{
		std::cout << "\n\n== Test Deep Copy ==\n";
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(10);
		
		Span sp2 = sp1;
		sp2.addNumber(10000);
		std::cout << "Sp1 original longest: " << sp1.longestSpan() << ": Should get 9" << "\n";
		std::cout << "Sp2 new longest: " << sp2.longestSpan() << ": Should get 9999" << "\n";
	}

	{
		std::cout << "\n\n== Test Exception ==\n";
		Span sp(1);
		try
		{
			sp.addNumber(52);
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
	}

	{
		std::cout << "\n\n== Test Negative/big numbers ==\n";
		Span sp(2);
		try
		{
			sp.addNumber(-9999);
			sp.addNumber(10);
			std::cout << "Longest Span: " << sp.longestSpan() << ": Should print 10009\n";
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
	}
}

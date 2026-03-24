/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:26:37 by yelu              #+#    #+#             */
/*   Updated: 2026/03/24 01:27:18 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;

	{
		int main() {
		Span sp(10000);
		std::vector<int> randomNums(10000);
		
		// Fill vector with numbers from 0 to 9999
		for (int i = 0; i < 10000; ++i) randomNums[i] = i;

		// Add them all at once
		sp.addRange(randomNums.begin(), randomNums.end());

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // Should be 1
		std::cout << "Longest: " << sp.longestSpan() << std::endl;   // Should be 9999
}
	}
}

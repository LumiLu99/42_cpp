/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:26:41 by yelu              #+#    #+#             */
/*   Updated: 2026/07/27 15:32:33 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <climits>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _vec;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void addNumber(int number);
		unsigned int longestSpan() const;
		unsigned int shortestSpan() const;
	
		class SpanFullException : public std::exception
		{
			const char *what() const throw();
		};
	
		class NotEnoughNumbersException : public std::exception
		{
			const char *what() const throw();
		};

		template <typename T>
		void addNumber(T begin, T end)
		{
			unsigned int dist = std::distance(begin, end);
			
			if (_vec.size() + dist > _N)
				throw SpanFullException();
			else
				_vec.insert(_vec.end(), begin, end);
		}
};
	

#endif
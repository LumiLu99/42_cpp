/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:26:39 by yelu              #+#    #+#             */
/*   Updated: 2026/03/24 13:30:21 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
	_vec.reserve(N);
}

Span::Span(const Span &other) : _N(other._N), _vec(other._vec) {}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_vec = other._vec;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(unsigned int number)
{
	if (_vec.size() >= _N)
		throw SpanFullException();
	_vec.push_back(number);
}

unsigned int Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());

	return (static_cast<unsigned int>(max - min));
}

unsigned int Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
	
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	
}


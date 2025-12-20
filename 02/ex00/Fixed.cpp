/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:06:00 by yelu              #+#    #+#             */
/*   Updated: 2025/12/20 03:15:20 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << "\n";
	fixedPointValue = src.getRawBits();
}

// Copy assignment operator
// We need to return a reference to the current object to allow chained assignments
// Fixed a, b, c; a = b = c;
// b = c happens first, this updates b. Then the result of b = c is assigned to a.
// By returning *this (a reference to the object that was just assigned to), b = c returns a reference to b
// b.operator=(c); a.opeartor=(b)

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &src)
	{
		fixedPointValue = src.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << "\n";
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
}

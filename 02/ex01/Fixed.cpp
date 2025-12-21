/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:06:00 by yelu              #+#    #+#             */
/*   Updated: 2025/12/16 14:49:00 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const int integer)
{
	fixedPointValue = integer << fractionalBits;
	std::cout << "Int constructor called" << "\n";
}
Fixed::Fixed(const float floatingPoint)
{
	fixedPointValue = roundf(floatingPoint * (1 << fractionalBits));
	std::cout << "Float constructor called" << "\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

Fixed::Fixed(const Fixed &src)
{
	fixedPointValue = src.getRawBits();
	std::cout << "Copy constructor called" << "\n";
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
	{
		fixedPointValue = src.getRawBits();
	}
	std::cout << "Copy assignment operator called" << "\n";
	return *this;
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

float Fixed::toFloat(void) const
{
	return ((float)fixedPointValue / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (fixedPointValue >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &input)
{
	out << input.toFloat();
	return out;
}
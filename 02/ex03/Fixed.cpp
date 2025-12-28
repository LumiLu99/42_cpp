/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:06:00 by yelu              #+#    #+#             */
/*   Updated: 2025/12/24 03:16:02 by yelu             ###   ########.fr       */
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
	fixedPointValue = src.fixedPointValue;
	std::cout << "Copy constructor called" << "\n";
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
	{
		fixedPointValue = src.fixedPointValue;
	}
	std::cout << "Copy assignment operator called" << "\n";
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}

bool Fixed::operator>(Fixed const &src) const
{
	return (this->fixedPointValue > src.fixedPointValue);
}

bool Fixed::operator<(Fixed const &src) const
{
	return (this->fixedPointValue < src.fixedPointValue);
}

bool Fixed::operator>=(Fixed const &src) const
{
	return (this->fixedPointValue >= src.fixedPointValue);
}

bool Fixed::operator<=(Fixed const &src) const
{
	return (this->fixedPointValue <= src.fixedPointValue);
}

bool Fixed::operator==(Fixed const &src) const
{
	return (this->fixedPointValue == src.fixedPointValue);
}

bool Fixed::operator!=(Fixed const &src) const
{
	return !(*this == src);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << "\n";
	return (fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
	return (fixedPointValue >> fractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)(fixedPointValue) / (1 << fractionalBits));
}

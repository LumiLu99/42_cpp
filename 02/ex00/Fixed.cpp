/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:06:00 by yelu              #+#    #+#             */
/*   Updated: 2025/12/15 16:22:16 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << "\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << "\n";
	fixedPointValue = src.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &src)
	{
		fixedPointValue = src.getRawBits();
	}
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

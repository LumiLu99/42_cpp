/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:06:00 by yelu              #+#    #+#             */
/*   Updated: 2025/12/30 10:23:18 by yelu             ###   ########.fr       */
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

// Comparison operators
// Last const mean the function itself will not modify the current object
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

Fixed Fixed::operator+(Fixed const &src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed const &src) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - src.getRawBits());
	return (result);
}

// Multiplication
// 1. Cast to long long to prevent overflow during multiplication
// 2. Multiply raw values
// 3. Shift right (divide) by fractional bits to reset scale
Fixed Fixed::operator*(const Fixed &src) const 
{
	Fixed result;
	long long temp;

	temp = (long long)this->fixedPointValue * (long long)src.fixedPointValue;
	result.setRawBits(temp >> fractionalBits); 
	return (result);
}

// Fixed Fixed::operator*(const Fixed &src) const
// {
//     return Fixed(this->toFloat() * src.toFloat());
// }

// Division
// 1. Cast to long long
// 2. Shift left (multiply) the numerator to gain precision
// 3. Divide by the denominator
Fixed Fixed::operator/(const Fixed &src) const 
{
	Fixed result;
	long long temp;

	temp = (long long)this->getRawBits() << fractionalBits;
	result.setRawBits(temp / src.getRawBits());
	return (result);
}

// Fixed Fixed::operator/(const Fixed &src) const
// {
//     return Fixed(this->toFloat() / src.toFloat());
// }

Fixed &Fixed::operator++()
{
	this->fixedPointValue++;
	return (*this);
}

// post-increment pass int to distinguish from pre-increment
// compiler passes 0 to that int parameter to trigger
// the correct version
Fixed Fixed::operator++(int)
{
	Fixed prev = *this;
	this->fixedPointValue++;
	return (prev);
}

// pre-decrement
Fixed &Fixed::operator--()
{
	fixedPointValue--;
	return (*this);
}

// post-decrement
Fixed Fixed::operator--(int)
{
	Fixed prev = *this;
	this->fixedPointValue--;
	return prev;
}

// A static member function min that takes two references to fixed-point numbers as
// parameters, and returns a reference to the smallest one
// Ternary Operator (condition) ? value_if_true : value_if_false
// Shorthand way of writing an if-else statement
// Public Overloaded Member Function: "Overloading" means giving 
// multiple functions the same name but different parameters.
// Static means the function belongs to the class generally, 
// not to any specific object. There is no this pointer.
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

// A static member function min that takes as parameters two references to CONSTANT
// fixed-point numbers, and returns a reference to the smallest one.
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

// A static member function max that takes as parameters two references on fixed-point
// numbers, and returns a reference to the greatest one.
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

// A static member function max that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the greatest one.
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}

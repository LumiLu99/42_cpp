/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:06:03 by yelu              #+#    #+#             */
/*   Updated: 2025/12/30 10:17:41 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool operator>(Fixed const &src) const;
		bool operator<(Fixed const &src) const;
		bool operator>=(Fixed const &src) const;
		bool operator<=(Fixed const &src) const;
		bool operator==(Fixed const &src) const;
		bool operator!=(Fixed const &src) const;

		Fixed operator+(Fixed const &src) const;
		Fixed operator-(Fixed const &src) const;
		Fixed operator*(Fixed const &src) const;
		Fixed operator/(Fixed const &src) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
	};
	
std::ostream &operator<<(std::ostream &out, const Fixed &src);


#endif

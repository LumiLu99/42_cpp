/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:06:03 by yelu              #+#    #+#             */
/*   Updated: 2025/12/15 15:47:17 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif

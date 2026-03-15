/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:21:39 by yelu              #+#    #+#             */
/*   Updated: 2026/03/15 17:06:06 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
	private:
		int			_x;
		std::string	_name;

	public:
		Data();
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();

		void	setName(const std::string name);
		void	setX(const int x);
		const std::string&	getName() const;
		int getX() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:21:42 by yelu              #+#    #+#             */
/*   Updated: 2026/03/15 17:07:05 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {}

Data::Data(const Data &other) : _x(other._x), _name(other._name) {}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_name = other._name;
	}
	return (*this);
}		

Data::~Data() {}

void Data::setName(const std::string name)
{
	this->_name = name;
}

void Data::setX(const int x)
{
	this->_x = x;
}

const std::string &Data::getName() const
{
	return (_name);
}

int Data::getX() const
{
	return (_x);
}

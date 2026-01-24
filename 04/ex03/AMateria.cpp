/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:09:21 by yelu              #+#    #+#             */
/*   Updated: 2026/01/23 06:43:30 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria " << _type << " type constructed!\n";
}

AMateria::AMateria(const AMateria &other)
{
	_type = other._type;
	std::cout << "AMateria (copy constructor): " << _type << " type copied!\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "AMateria (copy assignment): " << _type << " type copied!\n";
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructed!\n";
}

AMateria::AMateria(std::string const &type)
{
	this->_type = _type;
	std::cout << "AMateria (parameterized constructor): " << _type << " type constructed\n";
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}

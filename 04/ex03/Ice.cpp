/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:54:58 by yelu              #+#    #+#             */
/*   Updated: 2026/01/26 15:57:16 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Materia created!\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice Materia copied!\n";
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	std::cout << "Ice Materia assigned!\n";
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Materia destroyed!\n";
}

AMateria *Ice::clone() const
{
	std::cout << "Materia cloned!\n";
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

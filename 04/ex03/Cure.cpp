/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:29:44 by yelu              #+#    #+#             */
/*   Updated: 2026/01/25 17:11:00 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Materia created!\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure Materia copied!\n";
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	std::cout << "Cure Materia assigned!\n";
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Materia destroyed!\n";
}

// AMateria *Cure::clone() const
// {
// 	return new Cure(*this);
// }

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:22:19 by yelu              #+#    #+#             */
/*   Updated: 2026/01/15 12:56:56 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// OCF
WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "Animal type " << type << " spawned!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "Animal type " << type << " copy constructor called.\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "Animal type " << type << " copy assignment operator called.\n";
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal type " << type << " destructor called.\n";
}

// Getter
std::string	WrongAnimal::getType() const
{
	return (type);
}

// Actions
void    WrongAnimal::makeSound() const
{
	std::cout << "ANIMMMAAAALLLLL\n";
}

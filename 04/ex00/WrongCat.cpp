/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:22:16 by yelu              #+#    #+#             */
/*   Updated: 2026/01/15 12:56:45 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "Cat";
	std::cout << "Animal type " << type << " spawned!\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copy constructor called. Type " << type << " spawned!\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "Copy assignment operator called.\n I am now type " << type << ".\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Animal type " << type << " despawned!\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!\n";
}

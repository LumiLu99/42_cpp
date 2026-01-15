/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:23:06 by yelu              #+#    #+#             */
/*   Updated: 2026/01/15 12:48:42 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Animal type " << type << " spawned!\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copy constructor called. Type " << type << " spawned!\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy assignment operator called.\n I am now type " << type << ".\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Animal type " << type << " despawned!\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}

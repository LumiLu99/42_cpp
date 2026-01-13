/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:21:26 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 23:51:13 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// OCF
Animal::Animal() : type("Default")
{
	std::cout << "Animal type " << type << " spawned!\n";
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "Animal type " << type << " copy constructor called.\n";
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "Animal type " << type << " copy assignment operator called.\n";
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal type " << type << "destructor called.\n";
}

// Actions
void    Animal::makeSound()
{
	std::cout << "ANIMMMAAAALLLLL\n";
}

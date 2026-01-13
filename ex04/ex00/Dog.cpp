/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:23:08 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 23:21:38 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Animal type " << type << " spawned! Bark!\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copy constructor called. Animal type " << type << " spawned! Bark!\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy assignment operator called. Animal type " << type << " spawned! Bark!\n";
}

Dog::~Dog()
{
	std::cout << "Animal type " << type << " despawned!\n";
}

void Dog::makeSound()
{
	std::cout << "Bark!\n";
}

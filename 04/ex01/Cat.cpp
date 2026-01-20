/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:23:06 by yelu              #+#    #+#             */
/*   Updated: 2026/01/20 18:44:02 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Animal type " << type << " with ideas spawned!\n";
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
	delete brain;
	std::cout << "Animal type " << type << " and its brain despawned!\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}

std::string	Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}

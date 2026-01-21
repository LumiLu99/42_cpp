/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:23:06 by yelu              #+#    #+#             */
/*   Updated: 2026/01/21 18:25:33 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Cat class: Animal type " << type << " with ideas spawned!\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Cat class: Copy constructor called. Type " << type << " with new brain spawned!\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Cat class: Copy assignment operator called. I am now type " << type << ".\n";
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat class: Animal type " << type << " and its brain despawned!\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}

std::string	Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}

void	Cat::setIdea(int const index, std::string const idea)
{
	this->brain->setIdea(index, idea);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:23:08 by yelu              #+#    #+#             */
/*   Updated: 2026/01/21 18:33:35 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	brain = new Brain();
	type = "Dog";
	std::cout << "Dog class: Animal type " << type << " spawned with ideas!\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << " Dog class: Copy constructor called. Animal type " << type << " with ideas spawned!\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Dog class: Copy assignment operator called. Animal type " << type << " spawned!\n";
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog class: Animal type " << type << " and its brain despawned!\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark!\n";
}

std::string	Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}

void	Dog::setIdea(int const index ,std::string const idea)
{
	this->brain->setIdea(index, idea);
}

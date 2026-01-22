/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:23:08 by yelu              #+#    #+#             */
/*   Updated: 2026/01/22 16:45:46 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal()
{
	brain = new Brain();
	type = "Dog";
	std::cout << "Dog class: AAnimal type " << type << " spawned with ideas!\n";
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << " Dog class: Copy constructor called. AAnimal type " << type << " with ideas spawned!\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Dog class: Copy assignment operator called. Animal type " << type << " spawned!\n";
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog class: AAnimal type " << type << " and its brain despawned!\n";
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

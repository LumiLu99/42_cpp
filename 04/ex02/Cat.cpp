/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:23:06 by yelu              #+#    #+#             */
/*   Updated: 2026/01/22 16:42:58 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal()
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Cat class: AAnimal type " << type << " with ideas spawned!\n";
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Cat class: Copy constructor called. Type " << type << " with new brain spawned!\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Cat class: Copy assignment operator called. I am now type " << type << ".\n";
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat class: AAnimal type " << type << " and its brain despawned!\n";
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

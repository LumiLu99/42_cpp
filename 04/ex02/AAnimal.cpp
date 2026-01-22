/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:21:26 by yelu              #+#    #+#             */
/*   Updated: 2026/01/22 16:40:39 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// OCF
AAnimal::AAnimal() : type("Default")
{
	std::cout << "AAnimal default spawned!\n";
}

AAnimal::AAnimal(const AAnimal &other)
{
	this->type = other.type;
	std::cout << "AAnimal type " << type << " copy constructor called.\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "AAnimal type " << type << " copy assignment operator called.\n";
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal type default despawned.\n";
}

// Getter
std::string	AAnimal::getType() const
{
	return (type);
}

// Actions
void    AAnimal::makeSound() const
{
	std::cout << "ANIMMMAAAALLLLL\n";
}

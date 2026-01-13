/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:21:26 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 13:53:23 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// OCF
Animal::Animal()
{
    type = "Default";
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

// Parameterized constructor
Animal::Animal(std::string type)
{
    this->type = type;
    std::cout << "Parameterized constructor type " << type << " called.";
}


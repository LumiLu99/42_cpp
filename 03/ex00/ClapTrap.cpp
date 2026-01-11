/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:48:09 by yelu              #+#    #+#             */
/*   Updated: 2026/01/11 20:35:54 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// -------------------------
// Default constructor
ClapTrap::ClapTrap()
	: _hitPoints(10),
	_energyPoints(10),
	_attackDamage(0),
	_name("Default")
{
	std::cout << "ClapTrap \"Default\" spawned!" << "\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "Copy constructor called" << "\n";
}

// Copy Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	std::cout << "Copy assignment operator called" << "\n";
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << "\n";
}
// -----------------------

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints != 0)
	{
		if (amount > _hitPoints)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << _name << " is dead already!";
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints != 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
					<< ", causing " << _attackDamage << " points of damage!";
		_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << _name << " does not have enough energy!";
}


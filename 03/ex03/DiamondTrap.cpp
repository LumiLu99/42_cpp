/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:43:40 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 14:39:48 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// -------------------------
// Default constructor
DiamondTrap::DiamondTrap()
	: ClapTrap(),
	ScavTrap(),
	FragTrap()
{
	this->_name = "Default";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " spawned!" << "\n";
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	this->_name = other._name;
	std::cout << "Copy constructor called. DiamondTrap " << _name << " spawned!\n";
}

// Copy Assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Copy assignment operator called. I am now " << _name << "\n";
	return (*this);
}

/**
 * DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		MANUAL Copying everything by hand
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}
 */

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed!" << "\n";
}

// -----------------------
// Parameterized constructor
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	ScavTrap(name), 
	FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " spawned!" << "\n";
}

// Actions
void    DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << "\n";
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (amount >= static_cast<unsigned int>(_hitPoints))
		{
			_hitPoints = 0;
			std::cout << "DiamondTrap " << _name << " took " << amount << " points of damage and is now dead!" << "\n";
		}
		else
		{
			_hitPoints -= amount;
			std::cout << "DiamondTrap " << _name << " took " << amount << " points of damage!" << "\n";
		}
	}
	else
		std::cout << "DiamondTrap " << _name << " is dead already!" << "\n";
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "DiamondTrap " << _name << " is dead and cannot be repaired!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		_hitPoints += amount;
		_energyPoints -= 1;
		std::cout << "DiamondTrap " << _name << " is repaired by " << amount << " points!" << "\n";
	}
	else
		std::cout << "DiamondTrap " << _name << " does not have enough energy!" << "\n";
}


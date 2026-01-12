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
	: _name("Default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
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
	std::cout << "Copy constructor called. ClapTrap " << _name << " spawned!" << "\n";
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
	std::cout << "Copy assignment operator called. I am now " << _name << "\n";
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << "\n";
}
// -----------------------

// Parameterized constructor
ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap \"" << _name << "\" spawned!" << "\n";
}

// -------------------------
// Getter
std::string	ClapTrap::getName() const
{
	return (_name);
}

int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

// -------------------------
// --- Actions ---
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (amount >= static_cast<unsigned int>(_hitPoints))
		{
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and is now dead!" << "\n";
		}
		else
		{
			_hitPoints -= amount;
			std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << "\n";
		}
	}
	else
		std::cout << "ClapTrap " << _name << " is dead already!" << "\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
					<< ", causing " << _attackDamage << " points of damage!" << "\n";
		_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << _name << " does not have enough energy!" << "\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "ClapTrap " << _name << " healed " << amount << " points!" << "\n";
		_hitPoints += amount;
		_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << _name << " does not have enough energy!" << "\n";
}
// -------------------------
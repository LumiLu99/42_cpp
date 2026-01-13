/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:47:32 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 14:36:31 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// -------------------------
// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap \"Default\" spawned!" << "\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called. ScavTrap " << _name << " spawned!" << "\n";
}

// Copy Assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Copy assignment operator called. I am now " << _name << "\n";
	return (*this);
}

/**
 * ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        MANUAL Copying everything by hand
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        
        // Copy ScavTrap specific stuff (if any)
        this->_guardingGate = other._guardingGate;
    }
    return (*this);
}
 */

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << "\n";
}

// -----------------------
// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap \"" << _name << "\" spawned!" << "\n";
}

// -------------------------
// --- Actions ---
void	ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (amount >= static_cast<unsigned int>(_hitPoints))
		{
			_hitPoints = 0;
			std::cout << "ScavTrap " << _name << " took " << amount << " points of damage and is now dead!" << "\n";
		}
		else
		{
			_hitPoints -= amount;
			std::cout << "ScavTrap " << _name << " took " << amount << " points of damage!" << "\n";
		}
	}
	else
		std::cout << "ScavTrap " << _name << " is dead already!" << "\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target
					<< ", causing " << _attackDamage << " points of damage!" << "\n";
		_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << _name << " does not have enough energy!" << "\n";
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot be repaired!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "ScavTrap " << _name << " healed " << amount << " points!" << "\n";
		_hitPoints += amount;
		_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << _name << " does not have enough energy!" << "\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << "\n";
}

// Attack another ScavTrap
void ScavTrap::attack(ScavTrap &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target.getName()
					<< ", causing " << _attackDamage << " points of damage!" << "\n";
		target.takeDamage(_attackDamage);
		_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << _name << " does not have enough energy!" << "\n";
}

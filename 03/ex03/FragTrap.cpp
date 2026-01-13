/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:47:07 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 14:36:56 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// -------------------------
// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap \"Default\" spawned!" << "\n";
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called. FragTrap " << _name << " spawned!" << "\n";
}

// Copy Assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Copy assignment operator called. I am now " << _name << "\n";
	return (*this);
}

/**
 * FragTrap &FragTrap::operator=(const FragTrap &other)
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
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed!" << "\n";
}

// -----------------------
// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap \"" << _name << "\" spawned!" << "\n";
}

// -------------------------
// --- Actions ---
void	FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (amount >= static_cast<unsigned int>(_hitPoints))
		{
			_hitPoints = 0;
			std::cout << "FragTrap " << _name << " took " << amount << " points of damage and is now dead!" << "\n";
		}
		else
		{
			_hitPoints -= amount;
			std::cout << "FragTrap " << _name << " took " << amount << " points of damage!" << "\n";
		}
	}
	else
		std::cout << "FragTrap " << _name << " is dead already!" << "\n";
}

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " is dead and cannot attack!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target
					<< ", causing " << _attackDamage << " points of damage!" << "\n";
		_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << _name << " does not have enough energy!" << "\n";
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " is dead and cannot be repaired!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "FragTrap " << _name << " healed " << amount << " points!" << "\n";
		_hitPoints += amount;
		_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << _name << " does not have enough energy!" << "\n";
}

// Attack another FragTrap
void FragTrap::attack(FragTrap &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " is dead and cannot attack!" << "\n";
	}
	else if (_energyPoints != 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target.getName()
					<< ", causing " << _attackDamage << " points of damage!" << "\n";
		target.takeDamage(_attackDamage);
		_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << _name << " does not have enough energy!" << "\n";
}
void	FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " is trying to give you a high five!\n";
}


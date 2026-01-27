/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:48:57 by yelu              #+#    #+#             */
/*   Updated: 2026/01/26 17:53:59 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Character Default spawned!\n";
}

Character::Character(const Character &other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character " << _name << " copied!\n";
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
			}
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	std::cout << "Character " << _name << " assigned!\n";
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
		}
	}
	std::cout << "Character " << _name << " despawned!\n";
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Parameterized Character " << _name << " spawned!\n";
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break;
		}
	}
	std::cout << "Equipped " << (m ? m->getType() : "null") << " to " << _name << "'s inventory.\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >=4)
	{
		std::cout << "Invalid index to unequip from " << _name << "'s inventory.\n";
		return;
	}
	_inventory[idx] = NULL;
	std::cout << "Unequipped slot " << idx << " of " << _name << "'s inventory.\n";
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >=4)
	{
		std::cout << "Invalid index to use from " << _name << "'s inventory.\n";
		return;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
}

const std::string& Character::getName() const
{
	return (_name);
}

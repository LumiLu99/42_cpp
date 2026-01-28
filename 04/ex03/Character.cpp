/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:48:57 by yelu              #+#    #+#             */
/*   Updated: 2026/01/28 18:42:41 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		_floor[i] = NULL;
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
	for (int i = 0; i < 100; i++)
	{
			_floor[i] = NULL;
	}
	std::cout << "Character " << _name << " and inventory copied!\n";
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
		for (int i = 0; i < 100; i++)
		{
			if (_floor[i])
				delete _floor[i];
			_floor[i] = NULL;
		}
	}
	std::cout << "Character " << _name << " and inventory assigned!\n";
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
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i])
		{
			delete _floor[i];
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
	for (int i = 0; i < 100; i++)
	{
		_floor[i] = NULL;
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
			std::cout << "Equipped " << m->getType() << " to " << _name << "'s inventory.\n";
			return ;
		}
	}
	std::cout << _name << "'s inventory is full! Unable to equip\n";
}

// void Character::unequip(int idx)
// {
// 	int i = 0;

// 	if (idx < 0 || idx >=4)
// 	{
// 		std::cout << "Invalid index to unequip from " << _name << "'s inventory.\n";
// 		return;
// 	}
// 	while (i < 100)
// 	{
// 		if (_floor[i])
// 			i++;
// 		else if (!_floor[i])
// 		{
// 			_floor[i] = _inventory[idx];
// 			_inventory[idx] = NULL;
// 			break;
// 		}
// 	}
// 	if (i == 100)
// 		std::cout << "Floor is full of Materias! Unable to unequip Materia. Nothing happens.\n";
// 	else
// 		std::cout << "Unequipped slot " << idx << " of " << _name << "'s inventory.\n";
// }

void Character::unequip(int idx)
{
    int i = 0;

    if (idx < 0 || idx >=4 || !_inventory[idx])
    {
		std::cout << "Invalid index to unequip from " << _name << " inventory!\n";
        return;
    }
    while (i < 100)
    {
        if (_floor[i])
            i++;
        else
        {
            _floor[i] = _inventory[idx];
            _inventory[idx] = NULL;
            std::cout << "Unequipped slot " << idx << " of " << _name << "'s inventory.\n";
            return;
        }
    }
    std::cout << "Floor is full of Materias! Unable to unequip Materia. Nothing happens.\n";
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
	else
		std::cout << "Invalid or Empty Materia slot, cannot use spell!\n";
}

const std::string& Character::getName() const
{
	return (_name);
}

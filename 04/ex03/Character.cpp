/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:48:57 by yelu              #+#    #+#             */
/*   Updated: 2026/01/24 15:21:01 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.cpp"

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}
		
Character::Character(const Character &other)
{

}
Character Character::&operator=(const Character &other)
{

}

Character::~Character()
{

}

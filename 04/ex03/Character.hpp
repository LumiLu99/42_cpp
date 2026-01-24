/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:49:01 by yelu              #+#    #+#             */
/*   Updated: 2026/01/24 15:06:58 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character
{
	protected:
		std::string _name;
		AMateria *_inventory[4];

	public:
		Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
};

#endif
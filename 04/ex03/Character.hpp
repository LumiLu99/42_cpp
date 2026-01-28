/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:49:01 by yelu              #+#    #+#             */
/*   Updated: 2026/01/27 17:25:54 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_floor[100];

	public:
		Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
	
		Character(const std::string &name);

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		const std::string& getName() const;
};

#endif
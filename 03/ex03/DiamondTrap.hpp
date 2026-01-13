/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:43:47 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 11:24:02 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		// --- OCF --- 1) Default 2) Copy 3) Assignment 4) Destructor
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		// Parameterized constructor
		DiamondTrap(std::string name);

		// Actions
		void    whoAmI();
		using   ScavTrap::attack;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
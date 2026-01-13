/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:47:34 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 10:54:36 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// --- OCF --- 1) Default 2) Copy 3) Assignment 4) Destructor
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		// Parameterized constructor
		ScavTrap(std::string name);

		// --- Actions ---
		void	attack(const std::string& target);
		void	attack(ScavTrap &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void    guardGate();
};

#endif
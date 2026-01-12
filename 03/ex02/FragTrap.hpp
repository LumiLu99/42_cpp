/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:46:09 by yelu              #+#    #+#             */
/*   Updated: 2026/01/12 22:08:42 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        // --- OCF --- 1) Default 2) Copy 3) Assignment 4) Destructor
        FragTrap();
        FragTrap(const FragTrap &src);
        FragTrap &operator=(const FragTrap &src);
        ~FragTrap();

        // Parameterized constructor
        FragTrap(std::string name);

        // Actions
		void	attack(const std::string& target);
		void	attack(FragTrap &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
        void	highFivesGuys(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:48:06 by yelu              #+#    #+#             */
/*   Updated: 2026/01/11 20:12:11 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap Monster("Monster");

    std::cout << "Energy Points: " << Monster.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << Monster.getAttackDamage() << std::endl;
    Monster.whoAmI();
    Monster.attack("Target Dummy");
    Monster.takeDamage(30);
    Monster.beRepaired(20);
    Monster.guardGate();
    Monster.highFivesGuys();
}

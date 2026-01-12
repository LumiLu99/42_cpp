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

#include "ScavTrap.hpp"

int	main()
{
	std::cout << "### TESTING CONSTRUCTION ###\n\n";
    ScavTrap A("Robot_A");
    ScavTrap B("Robot_B");

    std::cout << "\n\n### TESTING SPECIAL CAPACITY (Gate Keeper) ###\n\n";
    A.guardGate();
    B.guardGate();

    std::cout << "\n### TESTING ATTACK & DAMAGE ###\n";
    A.attack("some random target");
    A.attack(B);
    std::cout << "Robot B has " << B.getHitPoints() << " hit points left.\n";
    B.beRepaired(10);
    std::cout << "Robot B has " << B.getHitPoints() << " hit points left.\n";
}

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

#include "FragTrap.hpp"

int	main()
{
	std::cout << "### TESTING CONSTRUCTION ###\n\n";
    FragTrap A("Robot_A");
    FragTrap B("Robot_B");

    std::cout << "\n\n### TESTING SPECIAL CAPACITY (High Fives) ###\n\n";
    A.highFivesGuys();
    B.highFivesGuys();

    std::cout << "\n### TESTING ATTACK & DAMAGE ###\n";
    A.attack("some random target");
    A.attack(B);
    std::cout << "Robot B has " << B.getHitPoints() << " hit points left.\n";
    B.beRepaired(10);
    std::cout << "Robot B has " << B.getHitPoints() << " hit points left.\n";
}

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

#include "ClapTrap.hpp"

int	main()
{
	{
		std::cout << "\n\n### TEST 1: ENERGY DEPLETION ###\n" << std::endl;
		ClapTrap Zombie("Zombie");
	
		// Attack 10 times to drain exactly 10 energy
		for (int i = 0; i < 10; i++) {
			Zombie.attack("Target Dummy");
		}
	
		// Attempt 11th action - SHOULD FAIL
		std::cout << "--- Attempting 11th action. This should fail ---" << std::endl;
		Zombie.attack("Target Dummy");
		Zombie.beRepaired(5); // Should also fail
	}

	{
		std::cout << "\n\n### TEST 2: ATTACKED THEN DEATH LOGIC ###\n" << std::endl;
		ClapTrap Skeleton("Skeleton");
	
		// 1. Kill the Skeleton (10 HP - 15 DMG = 0 HP)
		Skeleton.takeDamage(15); 
	
		// 2. Try to act while dead - THIS SHOULD FAIL
		std::cout << "--- Attempting to act while dead. This should fail ---" << std::endl;
		Skeleton.attack("Enemy");
		Skeleton.beRepaired(10);
	}

	{
		std::cout << "\n\n### TEST 3: DAMAGE RECOVERY ###\n" << std::endl;
		ClapTrap Steve("Steve");

		// 1. Take some damage
		Steve.takeDamage(5); // HP is now 5

		// 2. Repair
		Steve.beRepaired(3); // HP should be 8. Cost 1 Energy.

		// 3. Verify survival
		Steve.takeDamage(7); // HP should be 1. Still alive!
		Steve.attack("Adventurer"); // Should work
	}

	{
		std::cout << "### TEST 1: PARAMETERIZED CONSTRUCTOR ###" << std::endl;
    	// Creates 'A' using string constructor
		ClapTrap a("Robot A"); 
		a.takeDamage(5); // A has 5 HP now
		std::cout << "Robot A created and damaged. HP is " << a.getHitPoints() << "\n";
	
		std::cout << "\n### TEST 2: COPY CONSTRUCTOR ###" << std::endl;
		// Creates 'B' as a CLONE of 'A'.
		// Should print: "Copy constructor called"
		ClapTrap b(a);

		std::cout << "--- Independence Check ---" << std::endl;
		// Modify B. If copy is shallow/wrong, A might accidentally change too.
		b.takeDamage(4); 
		b.attack("Target Dummy");
		std::cout << "Robot A HP is now " << a.getHitPoints() << "\n";
		std::cout << "Robot B HP is now " << b.getHitPoints() << "\n";

		std::cout << "\n### TEST 3: COPY ASSIGNMENT OPERATOR ###" << std::endl;
		ClapTrap c("Robot C"); // Created with default/param constructor

		c = a; 

		std::cout << "--- Independence Check ---" << std::endl;
		c.takeDamage(100);
		std::cout << "Robot C HP is now " << c.getHitPoints() << "\n";
		// But object A should remain unaffected
		a.attack("Someone"); // Prove A is still alive
		std::cout << "Robot A HP is now " << a.getHitPoints() << "\n";
	}
}

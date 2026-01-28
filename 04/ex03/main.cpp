/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:09:24 by yelu              #+#    #+#             */
/*   Updated: 2026/01/28 18:44:37 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{

	// {
	// 	std::cout << "   ### Deep Copy Test ###   \n\n";
	// 	Character* cloud = new Character("Cloud Strife");
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	cloud->equip(src->createMateria("ice"));

	// 	Character* tifa = new Character(*cloud);

	// 	delete cloud;

	// 	ICharacter* dummy = new Character("Monster");
	// 	tifa->use(0, *dummy);

	// 	delete dummy;
	// 	delete tifa;
	// 	delete src;
	// }

	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;

	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp); 
	// 	me->unequip(0);

	// 	delete src;
	// 	delete tmp; 
	// 	delete me;
	// }
	
// 	{
// 		std::cout << "   ### Inventory Test ###   \n\n";
// 		IMateriaSource* src = new MateriaSource();
// 		src->learnMateria(new Ice());
// 		Character* zack = new Character("Zack");

// 		zack->equip(NULL);

// 		AMateria* unknown = src->createMateria("fire");
// 		if (unknown == NULL)
// 			std::cout << "\nCorrect: Unknown materia is NULL.\n";
// 		else
// 			std::cout << "\nFail: Unknown materia created!\n";

// 		std::cout << "\nFilling inventory...\n";
// 		zack->equip(src->createMateria("ice"));
// 		zack->equip(src->createMateria("ice"));
// 		zack->equip(src->createMateria("ice"));
// 		zack->equip(src->createMateria("ice"));

// 		std::cout << "\n\nShould say unable to equip here!\n\n";
// 		AMateria* extra = src->createMateria("ice");
// 		zack->equip(extra);

// 		delete extra;

// 		delete zack;
// 		delete src;
// }

	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Cure());
	// 	Character* aerith = new Character("Aerith");

	// 	AMateria* cure = src->createMateria("cure");
	// 	aerith->equip(cure);

	// 	std::cout << "\nUnequipping slot 0...\n\n";
	// 	aerith->unequip(0);

	// 	ICharacter* sephiroth = new Character("Sephiroth");
	// 	std::cout << "\nTrying to use slot 0 (Should do nothing)...\n\n";
	// 	aerith->use(0, *sephiroth);

	// 	delete sephiroth;
	// 	delete aerith;
	// 	delete src;
	// }

	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	
	// 	ICharacter* me = new Character("me");
	
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	
	// 	ICharacter* bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	
	// 	delete bob;
	// 	delete me;
	// 	delete src;
	// 	return 0;
	// }
}

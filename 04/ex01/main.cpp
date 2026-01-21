/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:21:32 by yelu              #+#    #+#             */
/*   Updated: 2026/01/21 18:53:14 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	// {
	// 	std::cout << "\n    ### Default cat constructor test ###\n\n";
	// 	Cat *cat = new Cat();
	// 	Cat *cat2 = new Cat();
	// 	cat->setIdea(0, "I am the first cat!");
	// 	cat2->setIdea(0, "I am the second cat!");
	// 	std::cout << cat->getIdea(0) << "\n";
	// 	std::cout << cat2->getIdea(0) << "\n";
	// 	delete cat;
	// 	delete cat2;
	// }

	// {
	// 	std::cout << "\n    ### Default dog constructor test ###\n\n";
	// 	Dog *dog = new Dog();
	// 	Dog *dog2 = new Dog();
	// 	dog->setIdea(0, "I am the first dog!");
	// 	dog2->setIdea(0, "I am the second dog!");
	// 	std::cout << dog->getIdea(0) << "\n";
	// 	std::cout << dog2->getIdea(0) << "\n";
	// 	delete dog;
	// 	delete dog2;
	// }

	// {
	// 	std::cout << "\n    ### Dog copy constructor test ###\n\n";
	// 	Dog *dog = new Dog();
	// 	dog->setIdea(0, "I am the first dog!");
	// 	std::cout << dog->getIdea(0) << "\n";
	// 	Dog *dog2 = new Dog(*dog);
	// 	std::cout << dog2->getIdea(0) << "\n";
	// 	dog2->setIdea(0, "I am the second dog!");
	// 	std::cout << dog2->getIdea(0) << "\n";
	// 	delete dog;
	// 	delete dog2;
	// }

	// 	{
	// 	std::cout << "\n    ### Cat copy constructor test ###\n\n";
	// 	Cat *cat = new Cat();
	// 	cat->setIdea(0, "I am the first cat!");
	// 	std::cout << cat->getIdea(0) << "\n";
	// 	Cat *cat2 = new Cat(*cat);
	// 	std::cout << cat2->getIdea(0) << "\n";
	// 	cat2->setIdea(0, "I am the second cat!");
	// 	std::cout << cat2->getIdea(0) << "\n";
	// 	delete cat;
	// 	delete cat2;
	// }
	
	// {
	// 	std::cout << "\n    ### Cat copy assignment test ###\n\n";
	// 	Cat *cat = new Cat();
	// 	Cat *cat2 = new Cat();
	// 	cat->setIdea(0, "Cat: Meow! I am the first cat!");
	// 	std::cout << cat->getIdea(0) << "\n";
	// 	cat2->setIdea(0, "You expected cat2 but it is ME, Human!");
	// 	std::cout << cat2->getIdea(0) << "\n";
	// 	*cat2 = *cat;
	// 	std::cout << cat2->getIdea(0) << "\n";
	// 	cat2->setIdea(0, "Cat2: Meow! I am the second cat!");
	// 	std::cout << cat2->getIdea(0) << "\n";
	// 	delete cat;
	// 	delete cat2;
	// }

	// {
	// 	std::cout << "\n    ### Dog copy assignment test ###\n\n";
	// 	Dog *dog = new Dog();
	// 	Dog *dog2 = new Dog();
	// 	dog->setIdea(0, "Dog: Bark! I am the first dog!");
	// 	std::cout << dog->getIdea(0) << "\n";
	// 	dog2->setIdea(0, "You expected dog2 but it is ME, Human!");
	// 	std::cout << dog2->getIdea(0) << "\n";
	// 	*dog2 = *dog;
	// 	std::cout << dog2->getIdea(0) << "\n";
	// 	dog2->setIdea(0, "Dog2: Bark! I am the second dog!");
	// 	std::cout << dog2->getIdea(0) << "\n";
	// 	delete dog;
	// 	delete dog2;
	// }
	
	{
		const Animal *animals[10];
		for (int i = 0; i < 5; i++)
		{
			std::cout << "New dog[" << i << "]\n";
			animals[i] = new Dog();
		}
		for (int i = 5; i < 10; i++)
		{
			std::cout << "New cat[" << i << "]\n";
			animals[i] = new Cat();
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << "Deleteing animal array [" << i << "]\n";
			delete animals[i];
		}
	}
	return 0;
}

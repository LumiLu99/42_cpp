/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:21:32 by yelu              #+#    #+#             */
/*   Updated: 2026/01/22 16:27:26 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// {
	// 	Dog *dog = new Dog();
	// 	Dog *dog2 = new Dog(*dog);
	// 	delete dog;
	// 	delete dog2;
	// }

	// {
		// const Animal* meta = new Animal();
		// const Animal* j = new Dog();
		// const Animal* i = new Cat();
	// 	Dog *A = new Dog();
	// 	A->makeSound();
	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound!
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	delete i;
	// 	delete j;
	// 	delete meta;
	// 	delete A;
	// }

	// {
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound?
	// 	meta->makeSound();
	// 	delete i;
	// 	delete meta;
	// }
	return 0;
}

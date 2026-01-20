/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:21:32 by yelu              #+#    #+#             */
/*   Updated: 2026/01/20 17:40:19 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		Dog basic;
		basic.setIdea(0, "I love bones");

		Dog tmp = basic;

		tmp.setIdea(0, "I love cats but I'm lying");

		std::cout << "Original Dog idea: " << basic.getIdea(0) << std::endl;
		std::cout << "Copy Dog idea: " << tmp.getIdea(0) << std::endl;
	
		delete j;
		delete i;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:48:59 by yelu              #+#    #+#             */
/*   Updated: 2026/03/18 19:23:02 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base	*generate(void)
{
	int random;

	std::srand(std::time(NULL));
	random = std::rand() % 3;
	std::cout << "Number: " << random << std::endl;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

// Dynamic cast attempts to convert parent pointer into child pointer. For example, if parent
// is actually an instance of class A, then dynamic_cast<A*>(parent) will return a valid pointer to A. 
// If parent is not an instance of A, it will return NULL.
// This allows us to check the type of the object at runtime and identify which class it belongs to.

void identify(Base *parent)
{
	if (dynamic_cast<A*>(parent))
		std::cout << "A" << "\n";
	else if (dynamic_cast<B*>(parent))
		std::cout << "B" << "\n";
	else if (dynamic_cast<C*>(parent))
		std::cout << "C" << "\n";

}

void identify(Base& parent)
{
	try
	{
		(void)dynamic_cast<A&>(parent);
		std::cout << "A\n";
		return ;
	}
	catch (std::exception &e) {}
	
	try
	{
		(void)dynamic_cast<B&>(parent);
		std::cout << "B\n";
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<C&>(parent);
		std::cout << "C\n";
		return ;
	}
	catch (std::exception &e) {}

	std::cout << "Unknown type cast\n";
}

// void identify(Base& parent)
// {
// 	try
// 	{
// 		(void)dynamic_cast<A&>(parent);
// 		std::cout << "A" << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		try
// 		{
// 			(void)dynamic_cast<B&>(parent);
// 			std::cout << "B" << std::endl;
// 		}
// 		catch (std::exception &e)
// 		{
// 			try
// 			{
// 				(void)dynamic_cast<C&>(parent);
// 				std::cout << "C" << std::endl;
// 			}
// 			catch (std::exception &e)
// 			{
// 				std::cerr << "Unknown type" << std::endl;
// 			}
// 		}
// 	}
// }

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
}
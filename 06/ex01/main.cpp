/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:35:18 by yelu              #+#    #+#             */
/*   Updated: 2026/03/15 17:19:24 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	{
		Data	test;
	
		test.setX(52);
		test.setName("Fishie");
	
		std::cout << "Original address: " << &test << "\n";
		uintptr_t raw = Serializer::serialize(&test);
		std::cout << "Serialized as integer: " << raw << "\n";
		Data* deserialized = Serializer::deserialize(raw);
		std::cout << "Deserialized address: " << deserialized << "\n";

		std::cout << "Deserialized Data - Name: " << deserialized->getName() << ", X: " << deserialized->getX() << "\n";
		std::cout << "Original Data - Name: " << test.getName() << ", X: " << test.getX() << "\n";
	}

	{
		std::cout << "\n### For fun ###\n";
		char static_str[] = "Hello";
		char *heap_str = new char[10];
		static const char *read_only = "Hello";

		std::cout << "Stack: " << (uintptr_t)static_str << "\n";
		std::cout << "Heap:  " << (uintptr_t)heap_str << "\n";
		std::cout << "Data:  " << (uintptr_t)read_only << "\n";
		std::cout << "Stack: " << &static_str << "\n";
		std::cout << "Heap:  " << &heap_str << "\n";
		std::cout << "Data:  " << &read_only << "\n";
		delete[] heap_str;
		// Stack grows downwards, heap grows upwards, data segment is usually in the middle. Addresses may vary based on the system and compiler optimizations.
	}
}

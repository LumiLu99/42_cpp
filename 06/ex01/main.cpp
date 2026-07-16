/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:35:18 by yelu              #+#    #+#             */
/*   Updated: 2026/07/15 15:22:19 by yelu             ###   ########.fr       */
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

	// {
	// 	int* p = new int(65);
	// 	char* ch = reinterpret_cast<char*>(p);
	// 	std::cout << *p << "\n";
	// 	std::cout << *ch << "\n";
	// 	std::cout << p << "\n";
	// 	std::cout << ch << "\n";
	// 	delete p;
	// }

	// {
	// 	std::cout << "\n### For fun ###\n";
	// 	char static_str[] = "Hello"; // stack array
	// 	char *heap_str = new char[10]; // heap allocation
	// 	static const char *read_only = "Hello";

	// 	std::cout << "Stack: " << (uintptr_t)static_str << "\n"; // address of stack array
	// 	std::cout << "Heap:  " << (uintptr_t)heap_str << "\n"; // address of heap allocation
	// 	std::cout << "Read only:  " << (uintptr_t)read_only << "\n"; // address of string literal
	// 	std::cout << "Stack: " << &static_str << "\n"; // address of the array object (same numeric address as static_str)
	// 	std::cout << "Heap:  " << &heap_str << "\n"; // address of pointer variable (on the stack)
	// 	std::cout << "Read only:  " << &read_only << "\n"; // address of the static pointer variable (in .data), not the string literals
	// 	delete[] heap_str;
	// 	// Stack grows downwards, heap grows upwards, data segment is usually in the middle. Addresses may vary based on the system and compiler optimizations.
	// 	// Their exact locations are operating system dependent
	// }
}

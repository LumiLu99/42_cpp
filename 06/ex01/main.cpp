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
	Data	test;

	// test.setX(52);
	// test.setName("Fishie");

	std::cout << "Original address: " << &test << "\n";
	uintptr_t raw = Serializer::serialize(&test);
	std::cout << "Serialized as integer: " << raw << "\n";

}

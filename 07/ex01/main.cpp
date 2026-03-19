/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:39:12 by yelu              #+#    #+#             */
/*   Updated: 2026/03/19 21:21:30 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Takes const reference
template <typename T>
void printElement(const T &element)
{
	std::cout << element << "\n";
}

// Takes non-const reference for int
void increment(int &num)
{
	num++;
	std::cout << num << "\n";
}

int main()
{
	// Int array
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = 5;
	iter(arr, len, printElement<int>);
	std::cout << "\n\n==Increment==\n";
	iter(arr, len, increment);

	// Const array
	std::cout << "\n\n== Const int==\n";
	const int c_arr[] = {6, 5, 4, 3, 2};
	const size_t c_len = 5;
	iter(c_arr, c_len, printElement<int>);

	// Test string array
	std::string str_arr[] = {"Hello", "Goodbye"};
	size_t str_len = 2;
	std::cout << "\n\n==String==\n";
	iter(str_arr, str_len, printElement<std::string>);
}
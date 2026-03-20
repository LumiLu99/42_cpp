/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:23:14 by yelu              #+#    #+#             */
/*   Updated: 2026/03/20 19:10:47 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	{
		std::cout << "== Vector test ==\n";
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(42);
	
		try
		{
			std::vector<int>::iterator it = easyfind(v, 42);
			std::cout << "Value exist: " << *it << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\n == Trying to find something that doesn't exist.. ==\n";
		try
		{
			std::vector<int>::iterator it = easyfind(v, 999);
			std::cout << "Found value at: " << *it << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n == Test Int Linked list ==\n";
		std::list<int> link;
		link.push_back(100);
		link.push_back(200);
		link.push_back(300);

		try
		{
			std::list<int>::iterator it = easyfind(link, 200);
			std::cout << "Value exist: " << *it << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	
}

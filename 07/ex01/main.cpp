/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:15:33 by yelu              #+#    #+#             */
/*   Updated: 2026/03/19 17:10:20 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void printElement(int const &ele)
{
    std::cout << ele << "\n";
}

#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = 5;
    iter(arr, len, printElement);
}
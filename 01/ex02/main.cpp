/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:54:24 by yelu              #+#    #+#             */
/*   Updated: 2025/11/28 01:52:02 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of str: " << &str << "\n";
    std::cout << "Address held by stringPTR: " << stringPTR << "\n";
    std::cout << "Address held by stringREF: " << &stringREF << "\n";
    std::cout << "Value of str: " << str << "\n";
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << "\n";
    std::cout << "Value pointed to by stringREF: " << stringREF << "\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:21:24 by yelu              #+#    #+#             */
/*   Updated: 2026/01/13 13:38:53 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
    // OCF
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        ~Animal();
    
    // Parameterized Constructor
        Animal(std::string type);
    // Actions
        void    makeSound();
};

#endif
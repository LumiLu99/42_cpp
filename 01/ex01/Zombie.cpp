/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:02:31 by yelu              #+#    #+#             */
/*   Updated: 2025/12/15 13:53:00 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " despawned." << "\n";
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiinnnzzzZ..." << "\n";
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}
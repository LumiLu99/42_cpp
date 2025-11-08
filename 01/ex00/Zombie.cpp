/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:09:24 by yelu              #+#    #+#             */
/*   Updated: 2025/11/08 23:24:54 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _Name = name;
    std::cout << "Zombie " << _Name << " spawned." << "\n";
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _Name << " despawned." << "\n";
}

void    Zombie::announce(void)
{
    std::cout << _Name << ": BraiiiiiinnnzzzZ..." << "\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:09:24 by yelu              #+#    #+#             */
/*   Updated: 2025/11/27 20:41:04 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << "Zombie " << _name << " spawned." << "\n";
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " despawned." << "\n";
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiinnnzzzZ..." << "\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:02:31 by yelu              #+#    #+#             */
/*   Updated: 2025/11/09 19:17:20 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A new zombie spawned." << "\n";
}

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

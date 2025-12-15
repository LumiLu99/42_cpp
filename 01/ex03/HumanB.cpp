/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:03:34 by yelu              #+#    #+#             */
/*   Updated: 2025/11/30 00:13:51 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name) {}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

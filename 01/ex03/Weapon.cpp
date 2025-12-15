/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:29:15 by yelu              #+#    #+#             */
/*   Updated: 2025/11/29 15:29:15 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp" 

Weapon::Weapon(const std::string &type) : type(type) {}

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string &newType)
{
    this->type = newType;
}


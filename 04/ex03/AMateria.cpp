/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:09:21 by yelu              #+#    #+#             */
/*   Updated: 2026/01/22 18:17:12 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "Materia " << _type << " type constructed!\n";
}

AMateria::AMateria(const AMateria &other)
{
	_type = other._type;
	std::cout << "Materia: " << _type << " type copied!\n";
}


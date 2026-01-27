/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:54:55 by yelu              #+#    #+#             */
/*   Updated: 2026/01/26 14:39:38 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_MATERIA_HPP
#define ICE_MATERIA_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
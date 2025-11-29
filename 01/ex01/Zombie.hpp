/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:02:29 by yelu              #+#    #+#             */
/*   Updated: 2025/11/28 00:39:07 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string	_name;
	public:
		~Zombie();
		void	announce(void);
		void	setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
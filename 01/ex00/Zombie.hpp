/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:09:28 by yelu              #+#    #+#             */
/*   Updated: 2025/11/08 23:42:14 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string	_Name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif
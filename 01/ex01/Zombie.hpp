/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:02:29 by yelu              #+#    #+#             */
/*   Updated: 2025/11/09 00:35:17 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

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

Zombie *zombieHorde(int N, std::string name);

#endif
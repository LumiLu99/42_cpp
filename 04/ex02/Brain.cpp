/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:09:32 by yelu              #+#    #+#             */
/*   Updated: 2026/01/21 17:02:57 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "New brain constructed!\n";
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called!\n";
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
		std::cout << "Brain copy assignment operator called!\n";		
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructed!\n";
}

std::string	Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}

void	Brain::setIdea(int const index, std::string const idea)
{
	this->ideas[index] = idea;
}

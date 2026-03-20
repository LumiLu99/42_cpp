/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:02:47 by yelu              #+#    #+#             */
/*   Updated: 2026/03/20 18:49:57 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int number);

class ValueNotFound : public std::exception
{
	public:
		const char *what() const throw();
};

#include "easyfind.tpp"

#endif
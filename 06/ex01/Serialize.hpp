/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:14:50 by yelu              #+#    #+#             */
/*   Updated: 2026/03/15 16:08:42 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstdint>

class Data;

class Serializer
{
	
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
	
};

#endif
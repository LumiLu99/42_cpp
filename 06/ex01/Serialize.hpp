/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:14:50 by yelu              #+#    #+#             */
/*   Updated: 2026/03/15 18:43:33 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>
// #include "Data.hpp"
class Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		// static Data*		deserialize(uintptr_t raw);

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:14:52 by yelu              #+#    #+#             */
/*   Updated: 2026/03/15 18:54:17 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Data*	Serializer::deserialize(uintptr_t raw)
// {
	
// }
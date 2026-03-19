/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:15:27 by yelu              #+#    #+#             */
/*   Updated: 2026/03/19 11:05:29 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename F>
void iter(T *address,  const size_t length, F function)
{
    if (!address || !function)
        return ;
    for (size_t i = 0; i < length; i++)
        function(address[i]);
}
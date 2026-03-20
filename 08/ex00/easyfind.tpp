/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:32:39 by yelu              #+#    #+#             */
/*   Updated: 2026/03/20 18:49:41 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int number)
{
	typename T::iterator it = std::find(container.begin(), container.end(), number);

	if (it == container.end())
		throw ValueNotFound();

	return (it);
}

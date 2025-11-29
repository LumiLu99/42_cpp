/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:06:48 by yelu              #+#    #+#             */
/*   Updated: 2025/11/08 22:06:48 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zom("Foo");
    zom.announce();
    Zombie *strange = newZombie("Strange");
    strange->announce();
    Zombie random("Random");
    random.announce();
    delete strange;
}

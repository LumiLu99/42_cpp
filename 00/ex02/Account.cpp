/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:42:04 by yelu              #+#    #+#             */
/*   Updated: 2025/09/30 18:00:46 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
	int balance = initial_deposit;
	std::cout << ";amount:" << balance << ";created";
}

void	Account::displayAccountsInfos( void )
{
	for (accounts::iterator i = accounts.begin(); i != accounts.end(), i++)
		std::cout << "index:" << i << ";amount:" << 
}

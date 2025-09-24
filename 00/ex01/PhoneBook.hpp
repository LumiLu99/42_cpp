/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:45:21 by yelu              #+#    #+#             */
/*   Updated: 2025/09/24 16:25:30 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "main.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
	private:
		Contact _contact[8];
		int _count;
	public:
		PhoneBook() 
		{
			_count = 0;
		}
		void addContact();
		void searchContact();
};

#endif

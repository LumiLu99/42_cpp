/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:45:21 by yelu              #+#    #+#             */
/*   Updated: 2025/09/22 15:19:55 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class PhoneBook
{
	public:
		void setName(std::string name);
		const std::string& getName() const;
		void addContact();


};

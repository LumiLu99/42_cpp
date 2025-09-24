/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:44:49 by yelu              #+#    #+#             */
/*   Updated: 2025/09/24 17:22:10 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string _PhoneNumber;
		std::string _DarkestSecret;

	public:
		void setFirstName(std::string &firstName);
		void setLastName(std::string &lastName);
		void setNickname(std::string &nickName);
		void setPhoneNumber(std::string &phoneNumber);
		void setDarkSecret(std::string &darkSecret);

		const std::string &getFirstName() const;
		const std::string &getLastName() const;
		const std::string &getNickname() const;
		const std::string &getPhoneNumber() const;
		const std::string &getDarkSecret() const;
};

#endif

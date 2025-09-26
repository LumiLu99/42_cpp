/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:09:04 by yelu              #+#    #+#             */
/*   Updated: 2025/09/26 21:04:11 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string &firstName)
{
	_FirstName = firstName;
}

const std::string& Contact::getFirstName() const
{
	return _FirstName;
}

void Contact::setLastName(std::string &lastName)
{
	_LastName = lastName;
}

const std::string& Contact::getLastName() const
{
	return _LastName;
}

void Contact::setNickname(std::string &nickName)
{
	_Nickname = nickName;
}

const std::string& Contact::getNickname() const
{
	return _Nickname;
}

void Contact::setPhoneNumber(std::string &phoneNumber)
{
	_PhoneNumber = phoneNumber;
}

const std::string& Contact::getPhoneNumber() const
{
	return _PhoneNumber;
}

void Contact::setDarkSecret(std::string &darkSecret)
{
	_DarkestSecret = darkSecret;
}

const std::string& Contact::getDarkSecret() const
{
	return _DarkestSecret;
}

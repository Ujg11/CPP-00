/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:03:55 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/18 17:14:55 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

Contact::Contact(void)
{
}
Contact::~Contact(void)
{
}

void	Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void	Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void	Contact::setNikname(std::string str)
{
	this->_nickname = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNikname(void) const
{
	return (this->_nickname);
}

std::string Contact::getPhone(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void	Contact::displayContact(void) const
{
	std::cout << "First Name: " << this->getFirstName() << std::endl;
	std::cout << "Last Name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNikname() << std::endl;
	std::cout << "Phone Number: " << this->getPhone() << std::endl;
	std::cout << "Darkest Secret: " << this->getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

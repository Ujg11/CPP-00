/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:54:51 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/13 12:55:33 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
	std::cout << "	La guia ha sido creada!	" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "	Borrando la guia " << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	str;

	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "First name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_size % 8].setFirstName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_size % 8].setLastName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Nikname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_size % 8].setNikname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Phone Number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_size % 8].setPhoneNumber(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Darkest Secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_size % 8].setDarkestSecret(str);
	}
	this->_size ++;
}

void	PhoneBook::search(void)
{
	std::string	str = "";
	int			index;
	int			i = 0;

	std::cout << "Llista de contactos: " << std::endl;
	displayTableHeader();
	while (i < this->_size)
	{
		displayPhoneBookContact(i);
		i++;
	}
	std::cout << "Que contacto deseas ver?" << std::endl;
	std::getline(std::cin, str);
	if (!str.empty())
	{
		if (str.length() == 1 && std::isdigit(str[0]))
		{
			index = std::stoi(str);
			if (index >= 1 && index <= 8)
			{
				std::cout << "Contacto " << index << ":" << std::endl;
				this->_contacts[index - 1].displayContact();
			}
			else
				std::cout << "Numero incorrecto" << std::endl;
		}
		else
			std::cout << "Numero incorrecto" << std::endl;
	}
}

void	PhoneBook::displayPhoneBookContact(int index)
{
	std::string	str;
	
	index++;
	std::cout << "|    " << index << "     |";
	str = this->_contacts[index].getFirstName();
	printString(str);
	str = this->_contacts[index].getLastName();
	printString(str);
	str = this->_contacts[index].getNikname();
	printString(str);
	std::cout << std::endl;
}
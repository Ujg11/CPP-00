/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:54:51 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/18 17:22:40 by ojimenez         ###   ########.fr       */
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
	bool		line = false;;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!line)
	{
		std::cout << "First name: ";
		std::getline(std::cin, str);
		if (str.empty())
			std::cout << "Escribe algo, no puede quedar vacio" << std::endl;
		else
		{
			this->_contacts[this->_size % 8].setFirstName(str);
			line = true;
		}
	}
	line = false;
	while (!line)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, str);
		if (str.empty())
			std::cout << "Escribe algo, no puede quedar vacio" << std::endl;
		else
		{
			this->_contacts[this->_size % 8].setLastName(str);
			line = true;
		}
	}
	line = false;
	while (!line)
	{
		std::cout << "Nikname: ";
		std::getline(std::cin, str);
		if (str.empty())
			std::cout << "Escribe algo, no puede quedar vacio" << std::endl;
		else
		{
			this->_contacts[this->_size % 8].setNikname(str);
			line = true;
		}
	}
	line = false;
	while (!line)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, str);
		if (str.empty())
			std::cout << "Escribe algo, no puede quedar vacio" << std::endl;
		else
		{
			this->_contacts[this->_size % 8].setPhoneNumber(str);
			line = true;
		}
	}
	line = false;
	while (!line)
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, str);
		if (str.empty())
			std::cout << "Escribe algo, no puede quedar vacio" << std::endl;
		else
		{
			this->_contacts[this->_size % 8].setDarkestSecret(str);
			line = true;
		}
	}
	this->_size ++;
	std::cout << std::endl << "	Contacto Anyadido!	" << std::endl;
}

void	PhoneBook::search(void)
{
	std::string	str = "";
	int			index;
	int			i = 0;

	std::cout << "Llista de contactos: " << std::endl;
	displayTableHeader();
	int	display = this->_size;
	if (this->_size > 8)
		display = 8;
	while (i < display)
	{
		displayPhoneBookContact(i - 1);
		i++;
	}
	if (this->_size == 0)
	{
		std::cout << "No hay contactos para ver" << std::endl << std::endl;
		return ;
	}
	std::cout << "Que contacto deseas ver?" << std::endl;
	std::cin >> str;
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
	else
		std::cout << "Escribe algo que lo dejaste vacio" << std::endl;
}

void	PhoneBook::displayPhoneBookContact(int index)
{
	std::string	str;
	int			pos;
	
	index++;
	pos = (index % 8);
	std::cout << "|    " << (pos + 1)<< "     |";
	str = this->_contacts[pos].getFirstName();
	printString(str);
	str = this->_contacts[pos].getLastName();
	printString(str);
	str = this->_contacts[pos].getNikname();
	printString(str);
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:02:46 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/18 16:20:35 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int	main(void)
{
	std::string	input;
	PhoneBook	guia;
	bool		bucle = true;
	
	std::cout << "Hola! Escriba la accion que quiera usar:" << std::endl;
	while (bucle)
	{
		std::cout << "ADD" << std::endl << "SEARCH" << std::endl << "EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> input;
		if (input.compare("ADD") == 0)
			guia.add();
		else if(input.compare("SEARCH") == 0)
			guia.search();
		else if(input.compare("EXIT") == 0)
			bucle = false;
		else
		{
			std::cout << "Palabra no encontrada" << std::endl;
			std::cout << std::endl;
		}
			
	}
}

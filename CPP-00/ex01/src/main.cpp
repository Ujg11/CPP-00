/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:02:46 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/13 13:13:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int	main(void)
{
	std::string	input;
	PhoneBook	guia;
	bool		bucle = true;
	
	while (bucle)
	{
		std::cout << "Hola! Escriba la accion que quiera usar:" << std::endl;
		std::cout << "ADD" << std::endl << "SEARCH" << std::endl << "EXIT";
		std::cin >> input;
		if (input.compare("ADD") == 0)
			guia.add();
		else if(input.compare("SEARCH") == 0)
			guia.search();
		else if(input.compare("EXIT") == 0)
			bucle = false;
		else
			std::cout << "Palabra no encontrada" << std::endl;
	}
	
}

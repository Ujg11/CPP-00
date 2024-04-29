/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:48:44 by ojimenez          #+#    #+#             */
/*   Updated: 2024/04/29 20:48:44 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("Uri", 60);
	Bureaucrat b2("Pablo", 1);
	Bureaucrat b3("Laura", 150);
	Bureaucrat b4("Mal", 151); //Habrá excepcion

	std::cout << b1 << std::endl;
	std::cout << "Incrementamos " << b1.getName() << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl << std::endl;
	
	std::cout << b2 << std::endl;
	std::cout << "Incrementamos " << b2.getName() << std::endl;
	b2.incrementGrade();//Habrá excepcion
	std::cout << b2<< std::endl << std::endl;

	std::cout << b3 << std::endl;
	std::cout << "Decrementamos " << b2.getName() << std::endl;
	b2.incrementGrade();//Habrá excepcion
	std::cout << b3<< std::endl << std::endl;
}
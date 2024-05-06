/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:48:44 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/02 17:39:24 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b1("Uri", 51);
	Form form("Contracte", 50, 10);
	
	std::cout << b1 << std::endl;
	std::cout << form << std::endl;
	std::cout << "Probamos de firmar el Form:" << std::endl;
	try 
	{
		b1.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Incrementamos " << b1.getName() << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl << std::endl;
	std::cout << "Lo intentamos de nuevo:" << std::endl;
	try 
	{
		b1.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

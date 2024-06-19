/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <<ojimenez@student.42barcelona>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:03:51 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/17 22:03:56 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main(void)
{
	Intern	novato;
	AForm	*form;
	Bureaucrat				bureucrat("Uri", 45);
	

	std::cout << std::endl;
	std::cout << "Turn: " << bureucrat.getName() << std::endl; 
	try
	{
		form = novato.makeForm("shrubbery request", "home");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		form = novato.makeForm("robotomy request", "Bender");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		form = novato.makeForm("presidential request", "Jefe");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

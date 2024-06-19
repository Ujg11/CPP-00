/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:53:11 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/19 17:53:11 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = cpy;
}

Intern &Intern::operator=(const Intern &cpy)
{
	(void)cpy;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *(Intern::*f[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
	std::string s[3] = {"shrubbery request", "robotomy request", "presidential request"};

	for (int i = 0; i < 3; i++)
	{
		if (!formName.empty() && formName == s[i])
			return ((this->*f[i])(target));
	}
	std::cout << "Instruction " << formName << " not found" << std::endl;
	return (NULL);
}

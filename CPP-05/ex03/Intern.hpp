/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:53:20 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/19 17:53:20 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		AForm *makeShrubbery(std::string target);
		AForm *makeRobotomy(std::string target);
		AForm *makePresidential(std::string target);
	public:
		Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &cpy);
		~Intern();

		
		AForm *makeForm(std::string formName, std::string target);
};


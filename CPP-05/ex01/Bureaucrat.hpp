/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:50:36 by ojimenez          #+#    #+#             */
/*   Updated: 2024/04/29 20:50:36 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		static int			HIGHEST_GRADE;
		static int			LOWEST_GRADE;
		
		void setGrade(int grade);

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &cpy);
		~Bureaucrat();

		std::string getName() const;
		int	getGrade() const;
		static int getHIGHEST_GRADE();
		static int getLOWEST_GRADE();

		void incrementGrade();
		void decrementGrade();

		//clases que heredan de exception (les classes son considerades com excepcions)
		class GradeTooHighException: public std::exception
		{
			public:
			//Funció heredada de std::exception que obté una descripció del error associat. S'executa al haber-hi una excepcio del tipus
				virtual const char	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};
//std::ostream: es una secuencia de salida de datos como la cout
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

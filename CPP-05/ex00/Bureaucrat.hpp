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

		//clases que heredan de out_of_range, que es subclase de exception
		class GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException(std::string exc);
		};
		class GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException(std::string exc);
		};
};
//std::ostream: es una secuencia de salida de datos como la cout
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

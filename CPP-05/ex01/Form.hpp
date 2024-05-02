/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:50:14 by ojimenez          #+#    #+#             */
/*   Updated: 2024/04/30 21:50:14 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		Form();
		Form(std::string name, int gSign, int gExec);
		Form(const Form &cpy);
		Form &operator=(const Form &cpy);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GgradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &f);



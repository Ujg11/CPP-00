/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:50:14 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/13 18:34:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm();
		AForm(std::string name, int gSign, int gExec);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &cpy);
		virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		virtual void executeConcrete() const = 0;

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
		class FormIsNotSignedException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif

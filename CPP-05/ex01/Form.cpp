/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:50:04 by ojimenez          #+#    #+#             */
/*   Updated: 2024/04/30 21:50:04 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _gradeSign(75), _gradeExecute(75)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gSign, int gExec): _name(name), _gradeSign(gSign), _gradeExecute(gExec)
{
	std::cout << "Form parameter constructor called" << std::endl;
	if (this->_gradeSign < Bureaucrat::getHIGHEST_GRADE())
		throw (Form::GradeTooHighException());
	else if (this->_gradeSign > Bureaucrat::getLOWEST_GRADE())
		throw (Form::GgradeTooLowException());
	if (this->_gradeExecute < Bureaucrat::getHIGHEST_GRADE())
		throw (Form::GradeTooHighException());
	else if (this->_gradeExecute > Bureaucrat::getLOWEST_GRADE())
		throw (Form::GgradeTooLowException());
}

Form::Form(const Form &cpy): _name(cpy._name), _gradeSign(cpy._gradeSign), _gradeExecute(cpy._gradeExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_signed = cpy._signed;
}

Form &Form::operator=(const Form &cpy)
{
	std::cout << "Form operator '=' called" << std::endl;
	if (this != &cpy)
	{
		this->_signed = cpy.getSigned();
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeRequiredToSign() const
{
	return (this->_gradeSign);
}

int Form::getGradeRequiredToExecute() const
{
	return (this->_gradeExecute);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char *Form::GgradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << ", form grade required to sign is " << f.getGradeRequiredToSign()
		<< " and grade required to execute is " << f.getGradeRequiredToExecute() << ". ";
	if (f.getSigned())
		out << "It is already signed" << std::endl;
	else
		out << "It hasn't signed yet";
	return (out);
}

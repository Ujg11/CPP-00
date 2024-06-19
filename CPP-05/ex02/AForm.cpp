/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:50:04 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/02 17:54:00 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _gradeSign(75), _gradeExecute(75)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gSign, int gExec): _name(name), _gradeSign(gSign), _gradeExecute(gExec)
{
	std::cout << "Form parameter constructor called" << std::endl;
	this->_signed = false;
	if (this->_gradeSign < Bureaucrat::getHIGHEST_GRADE())
		throw (AForm::GradeTooHighException());
	else if (this->_gradeSign > Bureaucrat::getLOWEST_GRADE())
		throw (AForm::GgradeTooLowException());
	if (this->_gradeExecute < Bureaucrat::getHIGHEST_GRADE())
		throw (AForm::GradeTooHighException());
	else if (this->_gradeExecute > Bureaucrat::getLOWEST_GRADE())
		throw (AForm::GgradeTooLowException());
}

AForm::AForm(const AForm &cpy): _name(cpy._name), _gradeSign(cpy._gradeSign), _gradeExecute(cpy._gradeExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_signed = cpy._signed;
}

AForm &AForm::operator=(const AForm &cpy)
{
	std::cout << "Form operator '=' called" << std::endl;
	if (this != &cpy)
	{
		this->_signed = cpy.getSigned();
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_gradeSign)
	{
		this->_signed = true;
	}
	else
	{
		throw (AForm::GgradeTooLowException());
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw (AForm::FormIsNotSignedException());
	else if (executor.getGrade() > this->_gradeExecute)
		throw (AForm::GgradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		this->executeConcrete();
	}
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeRequiredToSign() const
{
	return (this->_gradeSign);
}

int AForm::getGradeRequiredToExecute() const
{
	return (this->_gradeExecute);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char *AForm::GgradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormIsNotSignedException::what(void) const throw()
{
	return ("Form isn't signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << ", form grade required to sign is " << f.getGradeRequiredToSign()
		<< " and grade required to execute is " << f.getGradeRequiredToExecute() << ". ";
	if (f.getSigned())
		out << "It is already signed" << std::endl;
	else
		out << "It hasn't signed yet";
	return (out);
}

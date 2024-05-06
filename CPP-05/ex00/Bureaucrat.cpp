/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:50:53 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/02 18:47:15 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int Bureaucrat::HIGHEST_GRADE = 1;
int Bureaucrat::LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat defaul constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat name constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat:: Bureaucrat(const Bureaucrat &cpy): _name(cpy.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	std::cout << "Bureaucrat operator '=' called" << std::endl;
	if (this != &cpy)
	{
		this->_grade = cpy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade >= HIGHEST_GRADE && grade <= LOWEST_GRADE)
	{
		this->_grade = grade;
	}
	else if (grade < HIGHEST_GRADE)
	{
		this->_grade = 75;
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (grade > LOWEST_GRADE)
	{
		this->_grade = 75;
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
}

int Bureaucrat::getHIGHEST_GRADE()
{
	return (HIGHEST_GRADE);
}

int Bureaucrat::getLOWEST_GRADE()
{
	return (LOWEST_GRADE);
}


const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high, assigned 75");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low, assigned 75");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}

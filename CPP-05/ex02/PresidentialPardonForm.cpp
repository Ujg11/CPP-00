/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:20:09 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/18 11:20:09 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	this->_target = "No specificated";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialForm", 25, 5)
{
	std::cout << "PresidentialPardonForm target constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy): AForm(cpy)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	this->_target = cpy._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	AForm::operator=(cpy);
	this->_target = cpy._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->getName() << " destructor called" << std::endl;
}

void PresidentialPardonForm::executeConcrete() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget()
{
	return (this->_target);
}

void PresidentialPardonForm::setTarget(std::string target)
{
	this->_target = target;
}

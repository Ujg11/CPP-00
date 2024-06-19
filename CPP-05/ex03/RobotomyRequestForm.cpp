/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:19:45 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/18 11:19:45 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->_target = "No specificated";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyForm", 72, 45)
{
	std::cout << "RobotomyRequestForm target constructor called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy): AForm(cpy)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	this->_target = cpy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	AForm::operator=(cpy);
	this->_target = cpy._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->getName() << " destructor called" << std::endl;
}

void RobotomyRequestForm::executeConcrete() const
{
	std::cout << "Wait please (drilling noises in the background...)" << std::endl;
	//sleep(3);
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl; 
	else
		std::cout << this->_target << " robotomy's has failed";
}

std::string RobotomyRequestForm::getTarget()
{
	return (this->_target);
}

void RobotomyRequestForm::setTarget(std::string target)
{
	this->_target = target;
}

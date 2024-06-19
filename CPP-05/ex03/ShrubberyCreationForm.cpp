/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:19:19 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/18 11:19:19 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->_target = "No specificated";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy): AForm(cpy)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	this->_target = cpy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	AForm::operator=(cpy);
	this->_target = cpy._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " destructor called" << std::endl;
}

void ShrubberyCreationForm::executeConcrete() const
{
	std::ofstream file;

	file.open((this->_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "              v .   ._, |_  .,\n";
        file << "           `-._\\/  .  \\ /    |/_\n";
        file << "               \\\\  _\\, y | \\//\n";
        file << "         _\\_.___\\\\, \\\\/ -.\\||\n";
        file << "           `7-,--.`._||  / / ,\n";
        file << "           /'     `-. `./ / |/_.'\n";
        file << "                     |    |//\n";
        file << "                     |_    /\n";
        file << "                     |-   |\n";
        file << "                     |   =|\n";
        file << "                     |    |\n";
        file << "--------------------/ ,  . \\--------._\n";
		file.close();
		std::cout << "File " << this->_target + "_shrubbery" << " created succesfully" << std::endl;
	}
	else
	{
		std::cout << "Error in open the file" << std::endl;
	}
}

std::string ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}

void ShrubberyCreationForm::setTarget(std::string target)
{
	this->_target = target;
}

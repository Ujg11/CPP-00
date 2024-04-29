/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:55:20 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/07 12:30:38 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &cpy)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = cpy;
}

Ice &Ice::operator=(const Ice &cpy)
{
	std::cout << "Ice operator '=' called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	std::cout << std::endl << "Ice clone begining:" << std::endl;
	AMateria *ice = new Ice(*this);
	std::cout << "Ice clone ended" << std::endl << std::endl;
	return (ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

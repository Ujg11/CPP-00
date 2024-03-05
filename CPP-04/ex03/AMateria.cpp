/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:20:01 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/04 17:39:02 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	this->type = "Undefined";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria type constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &cpy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = cpy;
}

AMateria &AMateria::operator=(const AMateria &cpy)
{
	std::cout << "AMateria operator '=' called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "First I need to know wich materia I am before use on " << target.getName() << std::endl;
}

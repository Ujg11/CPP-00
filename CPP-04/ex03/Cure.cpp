/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:55:41 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/03 19:55:41 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &cpy)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = cpy;
}

Cure &Cure::operator=(const Cure &cpy)
{
	std::cout << "Cure operator '=' called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	AMateria *cure = new Cure(*this);
	return (cure);
}

void Cure::use(ICharacter& target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *";
}

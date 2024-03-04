/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:11:42 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/26 21:11:42 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = cpy;
}

Animal &Animal::operator=(const Animal &cpy)
{
	std::cout << "Animal '=' operator used" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

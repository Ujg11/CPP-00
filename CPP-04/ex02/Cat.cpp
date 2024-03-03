/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:11:36 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/26 21:11:36 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &cpy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cpy;
}

Cat &Cat::operator=(const Cat &cpy)
{
	std::cout << "Cat '=' operator used" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow...meow...meowwww" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->type);
}

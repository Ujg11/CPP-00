/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:23:39 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/07 12:09:50 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
	std::string idea = ""; 
	for (int i = 0; i < 100; i++)
	{
		idea = "Tengo una idea";
		this->ideas[i] = idea;
	}
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = cpy;
}

Brain &Brain::operator=(const Brain &cpy)
{
	std::cout << "Brain '=' operator called" << std::endl;
	if (this != &cpy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = cpy.getIdea(i);
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(std::string idea, int i)
{
	this->ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

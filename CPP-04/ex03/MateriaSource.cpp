/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:47:58 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/05 11:57:58 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = cpy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy)
{
	std::cout << "MateriaSource operator '=' called" << std::endl;
	if (this != &cpy)
	{
		for (int i = 0; i < 4; i++)
		{
			this->_materias[i] = cpy._materias[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

//Permet apendre Materies i fer plantilles
void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			std::cout << "Materia learned" << std::endl;
			this->_materias[i] = materia;
			return ;
		}
	}
	std::cout << "Sorry, it's full" << std::endl;
}

//Crea una materia a partir de les plantilles que hi ha
AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}

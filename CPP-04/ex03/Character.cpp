/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:35:10 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/03 18:35:10 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const name)
{
	std::cout << "Character name constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 10; i++)
		this->_trash[i] = NULL;
}

Character::Character(const Character &cpy)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = cpy;
}

Character &Character::operator=(const Character &cpy)
{
	std::cout << "Character operator '=' called" << std::endl;
	if (this != &cpy)
	{
		this->_name = cpy.getName();
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = cpy._inventory[i]->clone();
		for (int i = 0; i < 10; i++)
			this->_trash[i] = cpy._trash[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
	this->cleanTrash();
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Character " << this->getName() << " equiped" << std::endl;
			return ;
		}
	}
	std::cout << "The " << this->getName() << " inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Idx out of range, try between 0 and 3" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "You can't unequip because is empty" << std::endl;
		return ;
	}
	std::cout << "Character " << this->getName() << "unequiped correctly" << std::endl;
	this->addTrash(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Idx out of range, try between 0 and 3" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
	{
		std::cout << "Character " << this->getName() << " uses " << this->_inventory[idx]->getType();
		this->_inventory[idx]->use(target);
	}
}

void Character::cleanTrash()
{
	for (int i = 0; i < 10; i++)
	{
		if (this->_trash[i])
			delete this->_trash[i];
	}
}

void Character::addTrash(AMateria* m)
{
	for (int i = 0; i < 10; i++)
	{
		if (this->_trash[i] == NULL)
		{
			this->_trash[i] = m;
			return ;
		}
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:45 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/20 22:23:45 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "No c";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

//Default constructor
ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}
//Copy constructor
ClapTrap::ClapTrap(const ClapTrap &ct)
{
	*this = ct;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
	if (this != &ct)
	{
		this->_name = ct.getName();
		this->_hitPoints = ct.getHitPoints();
		this->_energyPoints = ct.getEnergyPoints();
		this->_attackDamage = ct.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
	
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

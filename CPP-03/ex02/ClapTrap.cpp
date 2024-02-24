/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:45 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/22 17:48:04 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor has been called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

//Default constructor
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor has been called" << std::endl;
	if (!name.empty())
		this->_name = name;
	else
		this->_name = "(null)";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}
ClapTrap::ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int attack)
{
	std::cout << "Initialize constructor has been called" << std::endl;
	if (!name.empty())
		this->_name = name;
	else
		this->_name = "(null)";
	this->_hitPoints = hit;
	this->_energyPoints = energy;
	this->_attackDamage = attack;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap &ct)
{
	std::cout << "Copy constructor has been called" << std::endl;
	*this = ct;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
	std::cout << "Operator '=' used"  << std::endl;
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
	std::cout << "Destructor of " << this->_name << " has been called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " don't have enough energy points to attack " << target << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " can't atack because is dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	bool flag = false;

	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead, stop please :(" << std::endl;
	}
	else if (this->_hitPoints > amount)
	{
		this->_hitPoints -= amount;
		flag = true;
	}
	else if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		flag = true;
	}
	if (flag)
	{
		std::cout << "ClapTrap " << this->_name << " has been attacked and has lost " << amount << " hit points. ";
		std::cout << "Now, " << this->_name << " has " << this->_hitPoints << " hit points." << std::endl;
	}	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has been repaired with " << amount << " points, ";
		std::cout << "now have " << this->_hitPoints << " of hit" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " don't have enough energy points to be repaired" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " can't be repaired because is dead" << std::endl;
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

void ClapTrap::setAttack(unsigned int attack)
{
	this->_attackDamage = attack;
}
void ClapTrap::setEnergy(unsigned int energy)
{
	this->_energyPoints = energy;
}

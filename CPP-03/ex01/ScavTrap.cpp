/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:19 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/22 17:55:08 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Undefined", 100, 50, 20)
{
	this->_guardGate = false;
	std::cout << "ScavTrap from ClapTrap default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	this->_guardGate = false;
	std::cout << "ScavTrap from ClapTrap " << name << " has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st): ClapTrap(st)
{
	std::cout << "ScavTrap from ClapTrap " << this->getName() << "has been copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st)
{
	std::cout << "ScavTrap operator '=' used"  << std::endl;
	ClapTrap::operator=(st);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << this->getName() << " has been called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing ";
		std::cout << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergy(getEnergyPoints() - 1);
	}
	else if (this->getEnergyPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " don't have enough energy points to attack " << target << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " can't atack because is dead" << std::endl;
}
void ScavTrap::guardGate()
{
	this->_guardGate = true;
	std::cout << "ScavTrap " << this->getName() << " is in guard keeper mode" << std::endl;
}

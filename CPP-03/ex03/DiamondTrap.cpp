/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:04:26 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/24 17:04:26 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Primer es crida el constructor de 

DiamondTrap::DiamondTrap(void): ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor has been called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = FragTrap::FTHhit;
	this->_energyPoints = ScavTrap::STEnergy;
	this->_attackDamage = FragTrap::FTAttack;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap name constructor has been called" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::FTHhit;
	this->_energyPoints = ScavTrap::STEnergy;
	this->_attackDamage = FragTrap::FTAttack;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy):ClapTrap(cpy.getName() + "_clap_name"), FragTrap(cpy.getName()), ScavTrap(cpy.getName())
{
	std::cout << "DiamondTrap copy constructor has been called" << std::endl;
	this->_name = cpy.getName();
	this->setHitPoints(cpy.getHitPoints());
	this->setEnergy(cpy.getEnergyPoints());
	this->setAttack(cpy.getAttackDamage());
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt)
{
	std::cout << "DiamondTrap operator '=' used" << std::endl;
	if (this != &dt)
	{
		this->_name = dt.getName();
		this->_hitPoints = dt.getHitPoints();
		this->_energyPoints = dt.getEnergyPoints();
		this->_attackDamage = dt.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor of DiamondTrap " << this->_name << " has been called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Hi! My DiamondTrap name is: " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl; 
}

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
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergy(ScavTrap::getEnergyPoints());
	this->setAttack(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap name constructor has been called" << std::endl;
	//this->setHitPoints(FragTrap::getHitPoints());
	this->_hitPoints = FragTrap::_hitPoints;
	this->setEnergy(ScavTrap::getEnergyPoints());
	this->setAttack(FragTrap::getAttackDamage());
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

}

DiamondTrap::~DiamondTrap(void)
{

}

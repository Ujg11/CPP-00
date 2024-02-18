/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:17 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/18 18:16:17 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_arma = nullptr;
}

HumanB::~HumanB(void)
{

}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_arma->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &arma)
{
	this->_arma = &arma;
}

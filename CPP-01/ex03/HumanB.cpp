/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:17 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/22 19:01:26 by ojimenez         ###   ########.fr       */
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
	if (!this->_arma->getType().empty())
		std::cout << this->_name << " attacks with their " << this->_arma->getType() << std::endl;
	else
		std::cout << this->_name << " don't have any weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &arma)
{
	this->_arma = &arma;
}

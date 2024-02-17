/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:10 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/17 14:32:10 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arma): _name(name), _arma(arma)
{
	
}

HumanA::~HumanA(void)
{

}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_arma.getType() << std::endl;
}
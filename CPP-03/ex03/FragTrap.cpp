/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:20:43 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/24 13:20:43 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Undefined", 100, 100, 30)
{
	std::cout << "FragTrap from ClapTrap default constructor has been called" << std::endl;
}


FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap from ClapTrap " << name << " has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft): ClapTrap(ft)
{
	std::cout << "FragTrap from ClapTrap " << this->getName() << "has been copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ft)
{
	std::cout << "FragTrap operator '=' used"  << std::endl;
	ClapTrap::operator=(ft);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap " << this->getName() << " has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey friends, high five!" << std::endl;
}

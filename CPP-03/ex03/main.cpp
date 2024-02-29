/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:52 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/29 16:27:58 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("Uri");
	std::cout << diamond.getName() << std::endl; //Usas la funcion de ClapTrap
	std::cout << diamond.getHitPoints() << std::endl;
	std::cout << diamond.getEnergyPoints() << std::endl;
	std::cout << diamond.getAttackDamage() << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;

	DiamondTrap diamond2;
	std::cout << diamond2.getName() << std::endl; //Usas la funcion de ClapTrap
	std::cout << diamond2.getHitPoints() << std::endl;
	std::cout << diamond2.getEnergyPoints() << std::endl;
	std::cout << diamond2.getAttackDamage() << std::endl;
	diamond2.whoAmI();
	std::cout << std::endl;

	diamond2.attack("hola");
	std::cout << std::endl;
	return (0);
}

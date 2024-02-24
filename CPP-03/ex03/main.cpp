/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:52 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/22 15:30:01 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	/*ScavTrap st("Scav Trap");
	std::cout << std::endl;
	FragTrap ft("Flag trap");
	std::cout << std::endl;
	FragTrap ft2;
	std::cout << std::endl;
	ClapTrap ct("Popeye");
	std::cout << std::endl;

	st.attack("A ese");
	st.setAttack(4);
	st.attack("A ese");
	st.takeDamage(30);
	st.beRepaired(10);

	ft.highFivesGuys();
	ft.attack("A aquel");
	ft.beRepaired(20);
	ft.takeDamage(50);

	ct.attack("Paco");*/

	DiamondTrap diamond("Uri");
	std::cout << diamond.getName() << std::endl;
	std::cout << diamond.getHitPoints() << std::endl;
	std::cout << diamond.getEnergyPoints() << std::endl;
	std::cout << diamond.getAttackDamage() << std::endl;

	return (0);
}

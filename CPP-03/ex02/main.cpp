/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:52 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/29 15:35:37 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap st("Scav Trap");
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
	ft.attack("A aquel");//Utilitza el metode de ClapTrap
	ft.beRepaired(20);
	ft.takeDamage(50);

	ct.attack("Paco");

	return (0);
}

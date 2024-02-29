/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:52 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/29 15:16:05 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap st("Robot");
	ScavTrap st2;
	ClapTrap ct("Popeye");

	st.attack("A ese");
	st.setAttack(4);
	st.attack("A ese");
	st.takeDamage(30);//el mensaje es el de ClapTrap
	st.beRepaired(10);//el mensaje es el de ClapTrap
	
	st.guardGate();
	ct.attack("Paco");

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:52 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/29 15:07:13 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct1;
	ClapTrap ct2("Popeye");
	ClapTrap ct3(ct1);

	ct1.attack("Popeye");
	ct2.takeDamage(ct1.getAttackDamage());
	
	ct1.setAttack(9);
	ct1.attack("Popeye");
	ct2.takeDamage(ct1.getAttackDamage());

	ct2.beRepaired(5);
	ct2.attack("default");
	ct2.setAttack(20);
	ct1.takeDamage(ct2.getAttackDamage());
	
	ct2.attack("default");
	ct1.takeDamage(ct2.getAttackDamage());

	return (0);
}
